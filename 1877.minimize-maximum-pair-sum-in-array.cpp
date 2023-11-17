/*
 * @lc app=leetcode id=1877 lang=cpp
 *
 * [1877] Minimize Maximum Pair Sum in Array
 */

// @lc code=start
class Solution {
  public:
    int minPairSum(vector<int>& nums) {
        int ans = 0;
        auto ptr1 = nums.begin(), ptr2 = nums.end();
        sort(ptr1, ptr2);
        ptr2--;
        while (ptr1 < ptr2) {
            int temp = *ptr1 + *ptr2;
            ans = (temp > ans) ? temp : ans;
            ptr1++;
            ptr2--;
        }

        return ans;
    }
};
// @lc code=end
