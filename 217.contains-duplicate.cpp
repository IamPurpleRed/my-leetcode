/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for (int n : nums) {
            if (s.count(n)) return true;
            else s.insert(n);
        }

        return false;
    }
};
// @lc code=end
