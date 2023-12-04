/*
 * @lc app=leetcode id=2264 lang=cpp
 *
 * [2264] Largest 3-Same-Digit Number in String
 */

// @lc code=start
class Solution {
  public:
    string largestGoodInteger(string num) {
        int large = -1;
        string ans;
        auto it = num.begin();
        while (it + 2 != num.end()) {
            if (*it == *(it + 1) && *it == *(it + 2)) {
                large = max(large, int(*it) - 48);
            }
            it++;
        }

        if (large == 0) return "000";
        else if (large == -1) return "";
        else return to_string(large * 111);
    }
};
// @lc code=end
