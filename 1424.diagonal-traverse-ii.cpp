/*
 * @lc app=leetcode id=1424 lang=cpp
 *
 * [1424] Diagonal Traverse II
 */

// @lc code=start

#define pli pair<long, int>
class Solution {
  public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        priority_queue<pli, vector<pli>, greater<pli>> pq;
        for (long r = 0; r < nums.size(); r++) {
            for (long c = 0; c < nums[r].size(); c++)
                pq.push(make_pair((r + c) * 1e5 + c, nums[r][c]));
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
// @lc code=end
