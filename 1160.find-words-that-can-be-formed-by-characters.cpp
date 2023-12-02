/*
 * @lc app=leetcode id=1160 lang=cpp
 *
 * [1160] Find Words That Can Be Formed by Characters
 */

// @lc code=start
class Solution {
  public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> num(26, 0);
        for (char c : chars) num[int(c) - 97]++;

        int ans = 0;
        for (string s : words) {
            bool status = true;
            vector<int> tmp = num;
            for (char c : s) {
                if (tmp[int(c) - 97] == 0) {
                    status = false;
                    break;
                }
                tmp[int(c) - 97]--;
            }
            if (status) ans += s.length();
        }

        return ans;
    }
};
// @lc code=end
