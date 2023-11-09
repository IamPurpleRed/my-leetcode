/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
  public:
    int sol[46] = {0};
    int fib(int n) {
        sol[1] = 1;

        return recursive(n);
    }

    int recursive(int n) {
        if (n == 0) return 0;
        if (sol[n] != 0)
            return sol[n];
        else {
            sol[n] = recursive(n - 1) + recursive(n - 2);
            return sol[n];
        }
    }
};
// @lc code=end
