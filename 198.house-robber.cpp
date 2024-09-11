/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        nums[2] += nums[0];
        for (auto it = nums.begin() + 3; it < nums.end(); it++)
            *it += max(*(it - 2), *(it - 3));

        return max(*(nums.end() - 1), *(nums.end() - 2));
    }
};
// @lc code=end

