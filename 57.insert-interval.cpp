/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
  public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> ans;
        const int size = intervals.size();
        int i = 0;

        while (i < size && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }

        while (i < size && intervals[i][0] <= newInterval[1]) {
            newInterval = {min(newInterval[0], intervals[i][0]),
                           max(newInterval[1], intervals[i][1])};
            i++;
        }
        ans.push_back(newInterval);

        while (i < size) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};
// @lc code=end
