/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
  private:
    vector<vector<char>> dict = {{},
                                 {},
                                 {'a', 'b', 'c'},
                                 {'d', 'e', 'f'},
                                 {'g', 'h', 'i'},
                                 {'j', 'k', 'l'},
                                 {'m', 'n', 'o'},
                                 {'p', 'q', 'r', 's'},
                                 {'t', 'u', 'v'},
                                 {'w', 'x', 'y', 'z'}};

  public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return {};
        queue<string> q;
        q.push("");
        int q_size = 1;
        for (char c : digits) {
            int d = c - '0';
            int loop = q_size;
            while (loop--) {
                string s = q.front();
                q.pop();
                q_size--;
                for (char c : dict[d]) {
                    q.push(s + c);
                    q_size++;
                }
            }
        }

        vector<string> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};
// @lc code=end
