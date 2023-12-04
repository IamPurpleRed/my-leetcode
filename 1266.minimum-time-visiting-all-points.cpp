/*
 * @lc app=leetcode id=1266 lang=cpp
 *
 * [1266] Minimum Time Visiting All Points
 */

// @lc code=start
class Solution {
  public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0, x = 0, y = 0;
        auto it = points.begin();
        while (it + 1 != points.end()) {
            x = abs((*it)[0] - (*(it + 1))[0]);
            y = abs((*it)[1] - (*(it + 1))[1]);
            ans += max(x, y);
            it++;
        }

        return ans;
    }
};
// @lc code=end
