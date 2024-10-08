/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
class Solution {
  public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        const int R = mat.size(), C = mat[0].size(), MAX = R * C;
        queue<pair<int, int>> q;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (!mat[i][j]) q.push({i, j});
                else mat[i][j] = MAX;
            }
        }

        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            pair<int, int> up = p;
            up.first--;
            pair<int, int> down = p;
            down.first++;
            pair<int, int> left = p;
            left.second--;
            pair<int, int> right = p;
            right.second++;
            vector<pair<int, int>> directions;
            directions.push_back(up);
            directions.push_back(down);
            directions.push_back(left);
            directions.push_back(right);
            for (auto d : directions) {
                if (d.first >= 0 && d.first < R && d.second >= 0 &&
                    d.second < C &&
                    mat[d.first][d.second] > mat[p.first][p.second] + 1) {
                    q.push({d.first, d.second});
                    mat[d.first][d.second] = mat[p.first][p.second] + 1;
                }
            }
        }

        return mat;
    }
};
// @lc code=end
