/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start
class Solution {
  public:
    int tribonacci(int n) {
        int ans[38] = {0};
        ans[1] = 1;
        ans[2] = 2;
        if (n < 3) return ans[n];
        for (int i = 3; i <= n; i++)
            ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];

        return ans[n];
    }
};
// @lc code=end
