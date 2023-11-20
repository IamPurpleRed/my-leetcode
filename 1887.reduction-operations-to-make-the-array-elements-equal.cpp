/*
 * @lc app=leetcode id=1887 lang=cpp
 *
 * [1887] Reduction Operations to Make the Array Elements Equal
 */

// @lc code=start
class Solution {
  public:
    int reductionOperations(vector<int>& nums) {
        int ans = 0, cnt = 0;
        map<int, int> m;
        for (int n : nums) {
            if (m[n] > 0) m[n]++;
            else m[n] = 1;
        }

        auto it = m.rbegin(), end = m.rend();
        end--;
        while (it != end) {
            cnt += it->second;
            ans += cnt;
            it++;
        }

        return ans;
    }
};
// @lc code=end
