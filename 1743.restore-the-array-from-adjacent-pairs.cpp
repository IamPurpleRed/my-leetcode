/*
 * @lc app=leetcode id=1743 lang=cpp
 *
 * [1743] Restore the Array From Adjacent Pairs
 */

// @lc code=start
class Solution {
  public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> um;
        for (vector<int>& v : adjacentPairs) {
            um[v[0]].push_back(v[1]);
            um[v[1]].push_back(v[0]);
        }

        int start = -1e5;
        for (auto entry : um) {
            if (entry.second.size() == 1) {
                start = entry.first;
                break;
            }
        }

        vector<int> ans;
        int left = 0, cnt = adjacentPairs.size();
        ans.push_back(start);

        while (cnt--) {
            vector<int>& val = um[start];
            int newval = (val[0] == left) ? val[1] : val[0];
            ans.push_back(newval);
            left = start;
            start = newval;
        }

        return ans;
    }
};
// @lc code=end
