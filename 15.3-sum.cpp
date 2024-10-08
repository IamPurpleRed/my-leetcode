/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
  public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // -4 -1 -1 0 1 2
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0) {
                if (nums[i] == nums[i - 1]) continue;
            }

            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] < 0) j++;
                else if (nums[i] + nums[j] + nums[k] > 0) k--;
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    int j_value = nums[j], k_value = nums[k];
                    do {
                        j++;
                    } while (nums[j] == j_value && j < k);
                }
            }
        }

        return ans;
    }
};
// @lc code=end
