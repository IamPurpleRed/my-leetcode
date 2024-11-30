/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
class Solution {
  public:
    int longestPalindrome(string s) {
        unordered_map<char, int> um;
        int odd = 0;
        for (char c : s) {
            if (!um.count(c)) {
                um[c] = 1;
                odd++;
            } else {
                um[c]++;
                if (um[c] & 1) odd++;
                else odd--;
            }
        }

        return (odd == 0) ? s.length() : s.length() - odd + 1;
    }
};
// @lc code=end
