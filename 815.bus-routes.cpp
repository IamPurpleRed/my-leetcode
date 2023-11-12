/*
 * @lc app=leetcode id=815 lang=cpp
 *
 * [815] Bus Routes
 */

// @lc code=start
class Solution {
  public:
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        unordered_map<int, vector<int>> busStops;
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                busStops[stop].push_back(i);
            }
        }

        int ans = 0;
        queue<int> q;
        set<int> busHadTaken;
        q.push(source);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int current = q.front();
                q.pop();
                cout << "current: " << current << ", ";
                if (current == target) return ans;
                for (int bus : busStops[current]) {
                    if (busHadTaken.count(bus)) continue;
                    cout << bus << " ";
                    busHadTaken.insert(bus);
                    for (int nextStop : routes[bus]) {
                        if (nextStop == current) continue;
                        q.push(nextStop);
                    }
                }
            }
            ans++;
            cout << endl;
        }

        return -1;
    }
};
// @lc code=end
