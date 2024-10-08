/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        for (vector<int> point : points) {
            vector<int> p = {(point[0] * point[0] + point[1] * point[1]),
                             point[0], point[1]};
            pq.push(p);
        }

        vector<vector<int>> ans;
        while (k) {
            vector<int> temp = pq.top();
            cout << temp[0] << endl;
            temp.erase(temp.begin());
            ans.push_back(temp);
            pq.pop();
            k--;
        }

        return ans;
    }
};
// @lc code=end
