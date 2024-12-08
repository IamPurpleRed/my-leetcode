/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int up = 0, right = matrix[0].size() - 1, down = matrix.size() - 1,
            left = 0;
        const int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int mode = 0, r = 0, c = 0;
        while (up <= down && left <= right) {
            ans.push_back(matrix[r][c]);
            if (mode == 0 && c == right) {  // up -> right
                mode++;
                up++;
            } else if (mode == 1 && r == down) {  // right -> down
                mode++;
                right--;
            } else if (mode == 2 && c == left) {  // down -> left
                mode++;
                down--;
            } else if (mode == 3 && r == up) {  // left -> up
                mode = 0;
                left++;
            }
            r += d[mode][0];
            c += d[mode][1];
        }

        return ans;
    }
};
// @lc code=end
