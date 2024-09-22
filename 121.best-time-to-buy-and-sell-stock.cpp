/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            buy = min(buy, prices[i]);
            profit = max(profit, prices[i] - buy);
        }

        return profit;
    }
};
// @lc code=end
