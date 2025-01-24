/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, min = prices[0];
        bool isHold = false;
        for (int i = 1; i < prices.size(); i++) {
            if (!isHold) {
                if (prices[i] < min) min = prices[i];
                else isHold = true;
            }

            if (isHold) {
                if (prices[i] < prices[i - 1]) {
                    ans += (prices[i - 1] - min);
                    isHold = false;
                    min = prices[i];
                }
            }
        }

        if (isHold) ans += (prices[prices.size() - 1] - min);

        return ans;
    }
};
// @lc code=end
