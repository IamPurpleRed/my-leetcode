/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
  public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> um;
        for (char c : s) um[c] = (um.count(c)) ? um[c] + 1 : 1;
        for (char c : t) {
            if (!um.count(c)) return false;
            else if (um[c] == 0) return false;
            else {
                um[c]--;
                if (um[c] == 0) um.erase(c);
            }
        }

        return um.empty() ? true : false;
    }
};
// @lc code=end
