/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
  public:
    int myAtoi(string s) {
        int ans = 0;
        bool hasDigit = false, digit = true;
        for (char c : s) {
            if (hasDigit == false) {
                if (c == ' ') continue;
                else if (c == '-') {
                    hasDigit = true;
                    digit = false;
                    continue;
                } else if (c == '+') {
                    hasDigit = true;
                    continue;
                }
            }

            if ('0' <= c && c <= '9') {
                hasDigit = true;
                if ((INT_MAX - c + '0') / 10 < ans)
                    return digit ? INT_MAX : INT_MIN;
                ans *= 10;
                ans += c - '0';
                cout << ans << endl;
            } else break;
        }

        return digit ? ans : -ans;
    }
};
// @lc code=end
