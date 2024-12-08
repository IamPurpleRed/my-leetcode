/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
  public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int n : nums) sum += n;
        if (sum & 1) return false;

        sum = sum >> 1;  // 只要能湊到 sum / 2，就回傳 true

        // https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
        /*  sol 1: 遞迴
         *  指針指向陣列的最後一個元素 (arr[-1])，
         *  首先要判斷 arr[-1] 是否大於 sum，
         *  如果大於，代表確定沒辦法，
         *  如果等於，就可以回傳 true，
         *  如果小於，只要以下其中一種方法回傳 true，就可以回傳 true：
         *  1. 組成 sum 的子集有 arr[-1] (take)
         *     -> 遞迴(指針指向arr[-2], sum - arr[-1])
         *  2. 組成 sum 的子集沒有 arr[-1] (not take)
         *     -> 遞迴(指針指向arr[-2], sum)
         *  因為每迭代一個元素就會有兩種可能，因此時間複雜度為 O(2^n)。
         */

        /* sol 3: DP (bottom-up)
         * 只需要記憶前一個元素的狀態即可
         */
        vector<bool> prev(sum + 1, false), current(sum + 1, false);
        // prev 代表前一個狀態，在當下代表為空陣列的情況下
        prev[0] = true;  // 無論鎮列為何，要湊出 0 是可行的
        for (int n : nums) {
            // for 迴圈到第 i 個元素的時候
            // prev[j] 代表 arr[0]~arr[i-1] 是否能湊出 j
            for (int j = 0; j <= sum; j++) {  // 0 ~ sum
                if (j < n) current[j] = prev[j];  // 組成 j 的集合中不可能會有 n
                else current[j] = (prev[j - n] || prev[j]);  // take or not take
            }
            prev = current;
        }

        return current[sum];
    }
};
// @lc code=end
