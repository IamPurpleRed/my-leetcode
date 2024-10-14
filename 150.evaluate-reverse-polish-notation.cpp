/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
  public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (string t : tokens) {
            if (isdigit(t[t.length() - 1])) s.push(stoi(t));
            else {
                int second = s.top();
                s.pop();
                int first = s.top();
                s.pop();
                int result = 0;
                if (t == "+") result = first + second;
                else if (t == "-") result = first - second;
                else if (t == "*") result = first * second;
                else if (t == "/") result = first / second;
                s.push(result);
            }
        }

        return s.top();
    }
};
// @lc code=end
