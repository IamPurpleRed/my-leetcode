/*
 * @lc app=leetcode id=2849 lang=cpp
 *
 * [2849] Determine if a Cell Is Reachable at a Given Time
 */

// @lc code=start
class Solution {
  public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x = abs(sx - fx), y = abs(sy - fy);
        if (x == 0 && y == 0 && t == 1) return false;
        return (max(x, y) <= t) ? true : false;
    }
};
// @lc code=end
