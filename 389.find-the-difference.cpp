/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */

// @lc code=start
class Solution {
  public:
    char findTheDifference(string s, string t) {
        int ascii_s = 0, ascii_t = 0;
        for (short i = 0; i < s.length(); i++) {
            ascii_s += int(s[i]);
        }
        for (short i = 0; i < t.length(); i++) {
            ascii_t += int(t[i]);
        }

        return char(ascii_t - ascii_s);
    }
};
// @lc code=end
