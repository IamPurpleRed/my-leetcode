/*
 * @lc app=leetcode id=1561 lang=cpp
 *
 * [1561] Maximum Number of Coins You Can Get
 */

// @lc code=start
class Solution {
  public:
    int maxCoins(vector<int>& piles) {
        int ans = 0;
        sort(piles.begin(), piles.end());
        auto it = piles.begin();
        while (it != piles.end()) {
            piles.pop_back();
            ans += *(piles.end() - 1);
            piles.pop_back();
            it++;
        }

        return ans;
    }
};
// @lc code=end
