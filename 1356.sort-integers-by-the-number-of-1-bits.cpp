/*
 * @lc app=leetcode id=1356 lang=cpp
 *
 * [1356] Sort Integers by The Number of 1 Bits
 */

// @lc code=start
class Solution {
  public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ans;
        vector<vector<int>> b;
        for (short i = 0; i < 14; i++) b.push_back(vector<int>());
        for (int n : arr) {
            short cnt = 0;
            for (short i = 0; i < 14; i++)
                if (n & (1 << i)) cnt++;
            for (short i = 0; i < b[cnt].size(); i++) {
                if (b[cnt][i] > n) {
                    b[cnt].insert(b[cnt].begin() + i, n);
                    break;
                } else if (i == b[cnt].size() - 1) {
                    b[cnt].push_back(n);
                    break;
                }
            }
            if (b[cnt].size() == 0) b[cnt].push_back(n);
        }
        for (vector<int> v : b) {
            for (int n : v) ans.push_back(n);
        }

        return ans;
    }
};
// @lc code=end
