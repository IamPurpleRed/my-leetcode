/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution {
  public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int row = grid.size(), col = grid[0].size();
        const vector<int> dr = {-1, 1, 0, 0}, dc = {0, 0, -1, 1};
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (grid[r][c] == 1) fresh++;
                if (grid[r][c] == 2) q.push({r, c});
            }
        }
        if (fresh == 0) return 0;
        if (q.empty()) return -1;
        int ans = 0;
        while (!q.empty()) {
            int current_rotten = q.size();
            while (current_rotten--) {
                pair<int, int> pos = q.front();
                cout << "pos: " << pos.first << " " << pos.second << endl;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int r = pos.first + dr[i], c = pos.second + dc[i];
                    if (r >= 0 && r < row && c >= 0 && c < col) {
                        if (grid[r][c] == 1) {
                            grid[r][c] = 2;
                            fresh--;
                            q.push({r, c});
                        }
                    }
                }
            }
            ans++;
        }

        return (fresh > 0) ? -1 : ans - 1;
    }
};
// @lc code=end
