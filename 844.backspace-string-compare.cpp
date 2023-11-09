/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
class Solution {
  public:
    bool backspaceCompare(string s, string t) {
        string s1, s2;
        for (char c : s) {
            if (c == '#') {
                if (s1.length() != 0) s1.pop_back();
            } else
                s1.push_back(c);
        }

        for (char c : t) {
            if (c == '#') {
                if (s2.length() != 0) s2.pop_back();
            } else
                s2.push_back(c);
        }

        return (s1 == s2);
    }
};
// @lc code=end
