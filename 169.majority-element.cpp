/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
// sol1: hash table -> time: O(n), space: O(n)
// sol2 -> time: O(log n), space: O(1)
class Solution {
  public:
    int majorityElement(vector<int>& nums) {
        const int size = nums.size(), reach = (size >> 1) + (size & 1);
        sort(nums.begin(), nums.end());
        int num = nums[0], count = 1;
        for (int i = 1; i < size; i++) {
            if (nums[i] == num) {
                count++;
                if (count == reach) return num;
            } else {
                num = nums[i];
                count = 1;
            }
        }

        return num;
    }
};
// sol3 -> time: O(n), space: O(1)
class Solution {
  public:
    int majorityElement(vector<int>& nums) {
        int num = 0, score = 0;

        for (int n : nums) {
            if (score == 0) num = n;

            if (num == n) score++;
            else score--;
        }

        return num;
    }
};
// num 不一定代表當前的眾數，但一定是最終的眾數
// 例如 2, 2, 2, 1, 3, 4, 5, 2, 2
// 讀到 5 的時候，num 會變成 5，但只會有 1 分
// 如果 2 的數量大於陣列的一半
// 那最後一定會再讓別人的分數歸零，並成為 num
// 或是讓分數大到，其它數字無法將分數歸零
// @lc code=end
