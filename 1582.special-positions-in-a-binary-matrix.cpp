/*
 * @lc app=leetcode id=1582 lang=cpp
 *
 * [1582] Special Positions in a Binary Matrix
 */

// @lc code=start
class Solution {
  public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        for (vector<int> r : mat) {
            int pos = -1;  // -1: not found yet, -2: more then 1
            for (int i = 0; i < r.size(); i++) {
                if (r[i] && pos != -1) {
                    pos = -2;
                    break;
                } else if (r[i]) {
                    pos = i;
                }
            }

            if (pos >= 0) {
                int cnt = 1;
                for (int c = 0; c < mat.size() && cnt >= 0; c++) {
                    if (mat[c][pos]) cnt--;
                }

                if (cnt == 0) ans++;
            }
        }

        return ans;
    }
};
// @lc code=end
