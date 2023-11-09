/*
 * @lc app=leetcode id=1503 lang=cpp
 *
 * [1503] Last Moment Before All Ants Fall Out of a Plank
 */

// @lc code=start
class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int nearest = 0;
        for (int i : left) nearest = max(i, nearest);
        for (int i : right) nearest = max(n - i, nearest);

        return nearest;
    }
};
// @lc code=end
