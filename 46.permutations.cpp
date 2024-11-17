/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
  public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtracking({}, nums);
        return ans;
    }

    void backtracking(vector<int> combination, vector<int> remains) {
        if (remains.empty()) {
            ans.push_back(combination);
            return;
        } else {
            set<int> s;
            for (auto it = remains.begin(); it < remains.end(); it++) {
                int value = *it;
                if (s.count(value)) continue;
                s.insert(value);
                remains.erase(it);
                combination.push_back(value);
                backtracking(combination, remains);
                combination.pop_back();
                remains.insert(it, value);
            }
        }
    }
};
// @lc code=end
