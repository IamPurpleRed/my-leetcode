/*
 * @lc app=leetcode id=1814 lang=cpp
 *
 * [1814] Count Nice Pairs in an Array
 */

// @lc code=start
class Solution {
  public:
    const int mod = 1e9 + 7;
    int countNicePairs(vector<int>& nums) {
        for (auto it = nums.begin(); it != nums.end(); it++) {
            int n = *it, rev = 0;
            while (n > 0) {
                rev = rev * 10 + n % 10;
                n /= 10;
            }
            *it -= rev;
        }

        sort(nums.begin(), nums.end());

        long ans = 0;
        for (auto it = nums.begin(); it < nums.end() - 1; it++) {
            long cnt = 1;
            while ((it < nums.end() - 1) && (*it == *(it + 1))) {
                cnt++;
                it++;
            }
            ans += cnt * (cnt - 1) / 2;
        }

        return (int)(ans % mod);
    }
};
// @lc code=end
