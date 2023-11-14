/*
 * @lc app=leetcode id=1930 lang=cpp
 *
 * [1930] Unique Length-3 Palindromic Subsequences
 */

// @lc code=start
class Solution {
  public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        set<char> side;
        for (auto it1 = s.begin(); it1 != s.end(); it1++) {
            if (side.count(*it1)) continue;
            side.insert(*it1);

            auto it2 = s.end() - 1;
            while (it1 != it2) {
                if (*it1 == *it2) break;
                it2--;
            }
            if (it1 == it2) continue;

            set<char> center;
            it2--;
            while (it1 != it2) {
                center.insert(*it2);
                it2--;
            }
            ans += center.size();
        }

        return ans;
    }
};
// @lc code=end
