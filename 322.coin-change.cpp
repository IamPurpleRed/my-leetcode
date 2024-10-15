/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
  public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> v(amount + 1, amount + 1);
        v[0] = 0;
        for (int i = 1; i <= amount; i++) {  // 計算湊到 i 元需要多少硬幣
            for (int c : coins) {            // 輪流嘗試每種面額
                if (i - c < 0) continue;  // 如果扣掉該面額小於 0，代表不可能
                if (v[i - c] < amount + 1) {  // v[i-c] = amount + 1
                                              // 代表沒有任何組合可以湊成 i 元
                    // 如果有硬幣可以湊到 i - c 元
                    // 代表 i 元需要的硬幣個數，等於 i - c 元需要的硬幣個數 + 1
                    // (個 c 元)
                    v[i] = min(
                        v[i],
                        v[i - c] +
                            1);  // 最後需比較這個個數有沒有比原本的少，取最少的方法
                }
            }
        }

        return (v[amount] == amount + 1) ? -1 : v[amount];
    }
};
// @lc code=end
