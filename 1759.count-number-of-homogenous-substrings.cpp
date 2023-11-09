/*
 * @lc app=leetcode id=1759 lang=cpp
 *
 * [1759] Count Number of Homogenous Substrings
 */

// @lc code=start
class Solution {
  public:
    int countHomogenous(string s) {
        const int MOD = 1e9 + 7;
        int idx = 0, ans = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != s[idx]) {
                for (int j = 1; j <= i - idx; j++) {
                    ans += j;
                    if (ans > MOD) ans = ans % MOD;
                }
                idx = i;
            }
        }

        for (int j = 1; j <= s.length() - idx; j++) {
            ans += j;
            if (ans > MOD) ans = ans % MOD;
        }

        return ans;
    }
};
// @lc code=end
