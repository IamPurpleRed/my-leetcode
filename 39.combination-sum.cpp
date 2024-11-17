/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
  public:
    vector<vector<int>> ans;
    int candidatesLen;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        candidatesLen = candidates.size();
        backtracking(target, {}, candidates, 0);
        return ans;
    }

    void backtracking(int target, vector<int> path, vector<int>& candidates,
                      int start) {
        if (target == 0) {
            ans.push_back(path);
            return;
        } else if (target < 0) {
            return;
        } else {
            /* start 變數在幹嘛？
            假設 candidates = {1, 2, 3}, target = 5
            為了避免把 {1, 2, 2} 和 {2, 1, 2} 視為不同的組合
            因此在 backtracking 多設了一個條件
            只能從 candidates[start] 開始尋找
            也就是說找了 2 之後，更深層的 backtracking 就不能再找 1，只能找 2 或
            3
            */
            for (int i = start; i < candidatesLen; i++) {
                path.push_back(candidates[i]);
                backtracking(target - candidates[i], path, candidates, i);
                path.pop_back();
            }
        }
    }
};
// @lc code=end
