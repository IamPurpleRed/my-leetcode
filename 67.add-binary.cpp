/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
  public:
    string addBinary(string a, string b) {
        string ans;
        int ptra = a.length() - 1, ptrb = b.length() - 1, carry = 0;
        while (ptra >= 0 || ptrb >= 0 || carry) {
            int total = carry;
            if (ptra >= 0) total += a[ptra--] - '0';
            if (ptrb >= 0) total += b[ptrb--] - '0';
            ans += (total & 1) + '0';
            carry = total >> 1;
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
// @lc code=end
