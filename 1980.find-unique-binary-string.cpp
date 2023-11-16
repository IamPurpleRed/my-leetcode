/*
 * @lc app=leetcode id=1980 lang=cpp
 *
 * [1980] Find Unique Binary String
 */

// @lc code=start
class Solution {
  public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        for (int i = 0; i < nums.size(); i++)
            ans += (nums[i][i] == '0' ? '1' : '0');

        return ans;
    }
};
// @lc code=end
