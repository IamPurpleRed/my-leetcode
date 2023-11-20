/*
 * @lc app=leetcode id=2391 lang=cpp
 *
 * [2391] Minimum Amount of Time to Collect Garbage
 */

// @lc code=start
class Solution {
  public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int m = -1, g = -1, p = -1, ans = 0, pos = garbage.size() - 1;
        for (auto it = garbage.end() - 1; it >= garbage.begin(); it--, pos--) {
            if (m == -1 && it->find("M") != string::npos) m = pos;
            if (g == -1 && it->find("G") != string::npos) g = pos;
            if (p == -1 && it->find("P") != string::npos) p = pos;
            ans += it->length();
        }

        for (int i = 0; i < m; i++) ans += travel[i];
        for (int i = 0; i < g; i++) ans += travel[i];
        for (int i = 0; i < p; i++) ans += travel[i];

        return ans;
    }
};
// @lc code=end
