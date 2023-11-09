/*
 * @lc app=leetcode id=2433 lang=cpp
 *
 * [2433] Find The Original Array of Prefix Xor
 */

// @lc code=start
class Solution {
  public:
    vector<int> ans;
    int prev = 0;
    for (int n : pref) {
        ans.push_back(n ^ prev);
        prev = n;
    }

    return ans;
};
// @lc code=end
