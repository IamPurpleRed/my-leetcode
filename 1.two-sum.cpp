/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIdx;
        for (int i = 0; i < nums.size(); i++) {
            const int n = nums[i];
            if (numToIdx.find(target - n) != numToIdx.end())
                return {numToIdx[target - n], i};
            numToIdx[n] = i;
        }

        return {};
    }
};
// @lc code=end
