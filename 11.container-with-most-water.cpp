/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
  public:
    int maxArea(vector<int>& height) {
        // two pointers 分別在最左邊和最右邊，兩邊開始往內縮
        // 越往內縮，代表寬度越窄，高度就要更高才有機會打破紀錄
        int ans = 0, ptr1 = 0, ptr2 = height.size() - 1;
        while (ptr1 < ptr2) {
            if (height[ptr1] < height[ptr2]) {
                ans = max(ans, height[ptr1] * (ptr2 - ptr1));
                ptr1++;
            } else {
                ans = max(ans, height[ptr2] * (ptr2 - ptr1));
                ptr2--;
            }
        }

        return ans;
    }
};
// @lc code=end
