/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution {
  public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> um;
        for (char c : magazine) {
            if (um.count(c)) um[c]++;
            else um[c] = 1;
        }
        for (char c : ransomNote) {
            if (um.count(c) == false || um[c] == 0) return false;
            else um[c]--;
        }

        return true;
    }
};
// @lc code=end
