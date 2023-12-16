/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
  public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;
        bool status = true;
        for (char c : s) {
            if (m[c]) m[c]++;
            else m[c] = 1;
        }
        for (char c : t) {
            if (!m[c]) {
                status = false;
                break;
            } else {
                m[c]--;
                if (m[c] == 0) m.erase(c);
            }
        }
        if (!m.empty()) status = false;

        return status;
    }
};
// @lc code=end
