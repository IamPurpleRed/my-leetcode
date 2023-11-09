/*
 * @lc app=leetcode id=1535 lang=cpp
 *
 * [1535] Find the Winner of an Array Game
 */

// @lc code=start
class Solution {
  public:
    int getWinner(vector<int>& arr, int k) {
        queue<int> q;
        int max_idx = 0, i = 0;
        for (int n : arr) {
            if (n > arr[max_idx]) max_idx = i;
            q.push(n);
            i++;
        }
        if (k >= max_idx) return arr[max_idx];

        int winner = q.front(), cnt = 0;
        q.pop();
        while (cnt != k) {
            int front = q.front();
            if (winner > front) {
                cnt++;
                q.push(front);
            } else {
                cnt = 1;
                q.push(winner);
                winner = front;
            }
            q.pop();
        }

        return winner;
    }
};
// @lc code=end
