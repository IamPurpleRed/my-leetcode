/*
 * @lc app=leetcode id=1838 lang=cpp
 *
 * [1838] Frequency of the Most Frequent Element
 */

// @lc code=start
class Solution {
  public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        auto left = nums.begin(), right = nums.begin();
        long sum = 0, len = 1, ans = 0;
        while (right < nums.end()) {
            sum += *right;
            while (sum + k < *right * len) {
                sum -= *left;
                left++;
                len--;
            }
            ans = max(ans, len);
            right++;
            len++;
        }

        return ans;
    }
};
// @lc code=end
