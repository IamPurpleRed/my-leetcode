/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        if (image[sr][sc] == color) return image;
        const int row = image.size(), col = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        while (!q.empty()) {
            int r = q.front().first, c = q.front().second;
            q.pop();
            if (image[r][c] == color) continue;
            if (r - 1 >= 0 && image[r - 1][c] == image[r][c])
                q.push({r - 1, c});
            if (r + 1 < row && image[r + 1][c] == image[r][c])
                q.push({r + 1, c});
            if (c - 1 >= 0 && image[r][c - 1] == image[r][c])
                q.push({r, c - 1});
            if (c + 1 < col && image[r][c + 1] == image[r][c])
                q.push({r, c + 1});
            image[r][c] = color;
        }

        return image;
    }
};
// @lc code=end
