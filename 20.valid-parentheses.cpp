/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
  public:
    bool isValid(string s) {
        unordered_map<char, char> um = {{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> st;
        for (char c : s) {
            if (st.empty()) st.push(c);
            else if (um[c] == st.top()) st.pop();
            else st.push(c);
        }

        return st.empty();
    }
};
// @lc code=end
