/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
  public:
    void sortColors(vector<int>& nums) {
        short ptr0 = 0, ptr2 = nums.size() - 1;
        while (ptr0 <= ptr2 && nums[ptr0] == 0) ptr0++;
        while (ptr0 <= ptr2 && nums[ptr2] == 2) ptr2--;

        short ptr = ptr0;
        while (ptr <= ptr2) {
            if (nums[ptr] == 0) swap(nums[ptr0++], nums[ptr++]);
            else if (nums[ptr] == 2) swap(nums[ptr2--], nums[ptr]);
            else ptr++;
        }
    }
};
// @lc code=end
