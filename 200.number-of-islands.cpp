/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
  public:
    int ans = 0;
    int row_size, col_size;
    vector<vector<int>> vis;
    queue<pair<int, int>> q;
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};

    void island(vector<vector<char>>& grid, int r, int c) {
        ans++;
        q.push({r, c});
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            vis[curr.first][curr.second] = 1;
            for (int i = 0; i < 4; i++) {
                int nr = curr.first + dx[i];
                int nc = curr.second + dy[i];

                if (nr >= 0 && nr < row_size && nc >= 0 && nc < col_size &&
                    grid[nr][nc] == '1' && vis[nr][nc] == 0) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        row_size = grid.size();
        col_size = grid[0].size();
        vis = vector<vector<int>>(row_size, vector<int>(col_size, 0));
        for (int r = 0; r < row_size; r++) {
            for (int c = 0; c < col_size; c++) {
                if (grid[r][c] == '1' && !vis[r][c]) {
                    island(grid, r, c);
                }
            }
        }

        return ans;
    }
};
// @lc code=end
