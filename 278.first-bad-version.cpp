/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
  public:
    int firstBadVersion(int n) {
        long long int start = 1, end = n, mid, ans;
        while (start <= end) {
            mid = (start + end) >> 1;
            if (isBadVersion(mid)) {
                ans = mid;
                end = mid - 1;
            } else start = mid + 1;
        }

        return ans;
    }
};
// @lc code=end
