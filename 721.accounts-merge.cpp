/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 */

// @lc code=start
class Solution {
  public:
    unordered_map<string, int> um;
    map<int, set<string>> m;

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for (int i = 0; i < accounts.size(); i++) {
            int duplicate = -1;
            string name = accounts[i][0];
            set<string> s;
            for (int j = 1; j < accounts[i].size(); j++) {
                s.insert(accounts[i][j]);
                if (um.count(accounts[i][j])) {
                    if (duplicate == -1) {
                        duplicate = um[accounts[i][j]];
                    } else if (duplicate != um[accounts[i][j]]) {
                        merge(um[accounts[i][j]], duplicate);
                    }
                }
            }
            if (duplicate == -1) {
                m[i] = s;
                for (auto it = s.begin(); it != s.end(); it++) {
                    um[*it] = i;
                }
            } else {
                for (auto it = s.begin(); it != s.end(); it++) {
                    um[*it] = duplicate;
                    m[duplicate].insert(*it);
                }
            }
        }

        vector<vector<string>> ans;
        for (auto it = m.begin(); it != m.end(); it++) {
            vector<string> v = {accounts[it->first][0]};
            v.insert(v.end(), it->second.begin(), it->second.end());
            ans.push_back(v);
        }

        return ans;
    }

    void merge(int from, int to) {
        for (auto it = m[from].begin(); it != m[from].end(); it++) {
            um[*it] = to;
            m[to].insert(*it);
        }
        m.erase(from);
    }
};
// @lc code=end
