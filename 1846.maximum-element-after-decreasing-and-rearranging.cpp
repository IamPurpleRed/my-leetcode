/*
 * @lc app=leetcode id=1846 lang=cpp
 *
 * [1846] Maximum Element After Decreasing and Rearranging
 */

// @lc code=start
class Solution {
  public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        auto current = arr.begin();
        if (*current != 1) *current = 1;
        auto prev = arr.begin();
        while (++current != arr.end()) {
            if (*current - *prev > 1) *current = *prev + 1;
            prev++;
        }

        return *prev;
    }
};
// @lc code=end
