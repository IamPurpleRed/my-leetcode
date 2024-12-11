/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
  public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        for (int n : nums) {
            vector<vector<int>> temp;
            for (vector<int> v : ans) {
                v.push_back(n);
                temp.push_back(v);
            }
            ans.insert(ans.end(), temp.begin(), temp.end());
        }

        return ans;
    }
};
// @lc code=end
