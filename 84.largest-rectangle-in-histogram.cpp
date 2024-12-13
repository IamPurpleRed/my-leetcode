/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
  public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<int> s;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++) {
            int currentHeight = heights[i];
            // s.top(): 目前在 stack 中，最高元素的 index
            while (!s.empty() && currentHeight < heights[s.top()]) {
                int sTopHeight = heights[s.top()];  // s.top() 的高度

                s.pop();  // top 換人了，sTopHeight 是「舊的」s.top() 的高度

                int width = (s.empty()) ? i : i - s.top() - 1;
                // 如果 stack 空了，代表 sTopHeight 是除了 currentHeight
                // 以外最短的 所以 0 到 i-1 的範圍都可以圍成，長 =
                // sTopHeight、寬 = i 的長方形 如果 stack
                // 還有元素，代表「新的」s.top() 比「舊的」s.top() 還短
                // 所以寬的範圍只有 s.top()+1 到 i-1，也就是 i - s.top() - 1
                // 因為 s.top()+1 到 i-1 的高度，一定 >= sTopHeight

                ans = max(ans, sTopHeight * width);
            }
            s.push(i);
        }

        return ans;
    }
};
// @lc code=end
