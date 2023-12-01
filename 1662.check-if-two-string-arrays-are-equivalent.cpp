/*
 * @lc app=leetcode id=1662 lang=cpp
 *
 * [1662] Check If Two String Arrays are Equivalent
 */

// @lc code=start
class Solution {
  public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1, str2;
        for (string s : word1) {
            str1 += s;
        }

        for (string s : word2) {
            str2 += s;
        }

        if (str1.length() != str2.length()) return false;
        for (int i = 0; i < str1.length(); i++)
            if (str1[i] != str2[i]) return false;

        return true;
    }
};
// @lc code=end
