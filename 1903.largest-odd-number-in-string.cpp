/*
 * @lc app=leetcode id=1903 lang=cpp
 *
 * [1903] Largest Odd Number in String
 */

// @lc code=start
class Solution {
  public:
    string largestOddNumber(string num) {
        int ptr = num.length() - 1;
        do {
            if ((int(num[ptr]) - 48) & 1) break;
            ptr--;
        } while (ptr >= 0);

        return num.substr(0, ptr + 1);
    }
};
// @lc code=end
