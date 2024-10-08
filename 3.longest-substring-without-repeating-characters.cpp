/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, current = 0;
        unordered_map<int, int> um;
        for (int i = 0; i < s.length(); i++) {
            if (um.count(s[i])) {
                for (int j = i - current; j <= um[s[i]]; j++) {
                    um.erase(s[j]);
                    current--;
                }
            }
            current++;
            ans = max(ans, current);
            um[s[i]] = i;
        }

        return ans;
    }
};
// @lc code=end
