/*
 * @lc app=leetcode id=1436 lang=cpp
 *
 * [1436] Destination City
 */

// @lc code=start
class Solution {
  public:
    string destCity(vector<vector<string>>& paths) {
        vector<string> ans;
        for (vector<string> path : paths) {
            ans.push_back(path[1]);
        }

        auto it = ans.begin();
        for (vector<string> path : paths) {
            while (it != ans.end()) {
                if (*it == path[0]) ans.erase(it);
                it++;
            }
        }

        return ans[0];
    }
};
// @lc code=end
