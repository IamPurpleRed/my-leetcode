/*
 * @lc app=leetcode id=1287 lang=cpp
 *
 * [1287] Element Appearing More Than 25% In Sorted Array
 */

// @lc code=start
class Solution {
  public:
    int findSpecialInteger(vector<int>& arr) {
        int len = arr.size();
        int current = arr[0], cnt = 0;
        for (int i : arr) {
            if (i != current) {
                current = i;
                cnt = 0;
            }
            cnt++;
            if ((cnt << 2) > len) break;
        }

        return current;
    }
};
// @lc code=end
