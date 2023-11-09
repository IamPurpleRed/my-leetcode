/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
  public:
    int sol[46] = {0};
    int climbStairs(int n) {
        sol[1] = 1;
        sol[2] = 2;

        return recursive(n);
    }

    int recursive(int n) {
        if (sol[n] != 0)
            return sol[n];
        else {
            sol[n] = recursive(n - 1) + recursive(n - 2);
            return sol[n];
        }
    }
};
// @lc code=end
