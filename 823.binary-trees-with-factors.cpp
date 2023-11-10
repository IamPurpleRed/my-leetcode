/*
 * @lc app=leetcode id=823 lang=cpp
 *
 * [823] Binary Trees With Factors
 */

// @lc code=start
#define ll long long
class Solution {
  private:
    const ll MOD = 1e9 + 7;

  public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        ll ans = 0;
        sort(arr.begin(), arr.end());
        set<int> s(arr.begin(), arr.end());
        map<int, ll> m;

        for (int i : arr) {
            m[i] = 1;
            for (int j : arr) {
                if (j > sqrt(i)) break;
                if ((i % j == 0) && s.count(i / j)) {
                    if (i / j == j) m[i] = (m[i] + m[j] * m[j]) % MOD;
                    else m[i] = (m[i] + m[j] * m[i / j] * 2) % MOD;
                }
            }
        }

        for (auto& member : m) ans = (ans + member.second) % MOD;

        return ans;
    }
};
// @lc code=end
