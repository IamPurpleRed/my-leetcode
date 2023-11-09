/*
 * @lc app=leetcode id=1921 lang=cpp
 *
 * [1921] Eliminate Maximum Number of Monsters
 */

// @lc code=start
class Solution {
  public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto i = dist.begin(), j = speed.begin(); i < dist.end();
             i++, j++) {
            pq.push((*i + *j - 1) / *j);
        }
        while (!pq.empty()) {
            if (pq.top() - ans <= 0) break;
            pq.pop();
            ans++;
        }

        return ans;
    }
};
// @lc code=end
