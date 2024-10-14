/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
  public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Kahn's algorithm
        vector<int> ans;
        unordered_map<int, vector<int>> um;  // 修 key 前要先修完 value
        unordered_map<int, int> indegree;    // 有 value 條線指向 key
        for (vector<int> v : prerequisites) {
            if (um.count(v[0])) um[v[0]].push_back(v[1]);
            else um[v[0]] = vector<int>{v[1]};

            if (indegree.count(v[1])) indegree[v[1]]++;
            else indegree[v[1]] = 1;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            // cout << indegree[i] << endl;
            if (indegree[i] == 0)
                q.push(i);  // 尋找沒有被指向的課，代表它們是圖的起點
        }

        while (!q.empty()) {
            int c = q.front();
            q.pop();
            ans.push_back(c);

            for (int p : um[c]) {  // 尋訪所有修 c 課前要修的課
                indegree[p]--;     // 少一線指向它
                if (indegree[p] == 0)
                    q.push(p);  // 如果 -1 後沒有線指向它，代表它就可以被放入
                                // queue 處理了
            }
        }

        return (ans.size() ==
                numCourses);  // 如果所有課都有在 ans 上，代表不是 DAG
    }
};
// @lc code=end
