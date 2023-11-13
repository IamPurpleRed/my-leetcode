/*
 * @lc app=leetcode id=2785 lang=cpp
 *
 * [2785] Sort Vowels in a String
 */

// @lc code=start
class Solution {
  public:
    string sortVowels(string s) {
        vector<int> ch = {65, 69, 73, 79, 85, 97, 101, 105, 111, 117};
        vector<int> v(10, 0);
        queue<int> q;

        int idx = 0;
        for (int ascii : s) {
            switch (ascii) {
                case 65:
                    v[0]++;
                    q.push(idx);
                    break;
                case 69:
                    v[1]++;
                    q.push(idx);
                    break;
                case 73:
                    v[2]++;
                    q.push(idx);
                    break;
                case 79:
                    v[3]++;
                    q.push(idx);
                    break;
                case 85:
                    v[4]++;
                    q.push(idx);
                    break;
                case 97:
                    v[5]++;
                    q.push(idx);
                    break;
                case 101:
                    v[6]++;
                    q.push(idx);
                    break;
                case 105:
                    v[7]++;
                    q.push(idx);
                    break;
                case 111:
                    v[8]++;
                    q.push(idx);
                    break;
                case 117:
                    v[9]++;
                    q.push(idx);
                    break;
            }
            idx++;
        }

        int ptr = 0;
        while (!q.empty()) {
            idx = q.front();
            q.pop();
            while (!v[ptr]) ptr++;
            s[idx] = char(ch[ptr]);
            v[ptr]--;
        }

        return s;
    }
};
// @lc code=end
