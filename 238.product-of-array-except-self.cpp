/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sum = 1;
        int zeros = 0;
        for (int n : nums) {
            if (n != 0) sum *= n;
            else zeros++;
        }
        if (zeros > 1) return vector(nums.size(), 0);
        else if (zeros == 1) {
            for (int i = 0; i < nums.size(); i++) {
                nums[i] = (nums[i] == 0) ? sum : 0;
            }
        } else {
            for (int i = 0; i < nums.size(); i++) {
                nums[i] = sum / nums[i];
            }
        }

        return nums;
    }
};
// @lc code=end
