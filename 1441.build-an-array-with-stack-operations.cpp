/*
 * @lc app=leetcode id=1441 lang=cpp
 *
 * [1441] Build an Array With Stack Operations
 */

// @lc code=start
class Solution {
  public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int cnt = 0;
        for (int n : target) {
            while (++cnt != n) {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            ans.push_back("Push");
        }

        return ans;
    }
};
// @lc code=end
