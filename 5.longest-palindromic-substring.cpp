/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
  public:
    short len;
    string longestPalindrome(string s) {
        len = s.length();
        string oddstr = odd(s);
        string evenstr = even(s);
        cout << oddstr << endl << evenstr << endl;
        return (oddstr.length() > evenstr.length()) ? oddstr : evenstr;
    }

    string odd(string s) {
        short start = 0, end = 0;
        for (short i = 0; i < len; i++) {
            short temps = i, tempe = i;
            while (temps - 1 >= 0 && tempe + 1 < len) {
                if (s[temps - 1] == s[tempe + 1]) {
                    temps--;
                    tempe++;
                } else
                    break;
            }
            if (tempe - temps + 1 > end - start + 1) {
                start = temps;
                end = tempe;
            }
        }

        return s.substr(start, end - start + 1);
    }

    string even(string s) {
        short start = 0, end = 0;
        for (short i = 0; i < len - 1; i++) {
            short temps = i + 1, tempe = i;
            while (temps - 1 >= 0 && tempe + 1 < len) {
                if (s[temps - 1] == s[tempe + 1]) {
                    temps--;
                    tempe++;
                } else
                    break;
            }
            if (temps < tempe && tempe - temps + 1 > end - start + 1) {
                start = temps;
                end = tempe;
            }
        }
        cout << start << end << endl;
        return (start == end) ? "" : s.substr(start, end - start + 1);
    }
};
// @lc code=end
