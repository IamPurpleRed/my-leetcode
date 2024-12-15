/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 */

// @lc code=start
class Solution {
  public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        const int n = startTime.size();
        vector<vector<int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());  // 越前面的工作，越早開始
        sort(startTime.begin(), startTime.end());
        vector<int> dp(n + 1,
                       0);  // dp[i]: 第 0 ~ n-1
                            // 份工作中，可以拿到的最大報酬，dp[n]: 不接任何工作
        return recursive(jobs, startTime, dp, n, 0);  // dp[0]
    }

    int recursive(vector<vector<int>>& jobs, vector<int>& startTime,
                  vector<int>& dp, const int& n, int i) {
        if (i >= n || i == -1) return 0;
        if (dp[i] != 0) return dp[i];

        // 如果選擇接第 i 份工作，下一份工作的 startTime 至少要 <= 第 i 份工作的
        // endTime lower_bound: 尋找 >= jobs[i][1] 的最小值 upper_bound: 尋找 >
        // jobs[i][1] 的最小值
        int next_job =
            lower_bound(startTime.begin(), startTime.end(), jobs[i][1]) -
            startTime.begin();
        int take = jobs[i][2] + recursive(jobs, startTime, dp, n, next_job);

        // 如果不接第 i 份工作，下一份工作就是第 i + 1 份
        int not_take = recursive(jobs, startTime, dp, n, i + 1);
        dp[i] = max(take, not_take);

        return dp[i];
    }
};
// @lc code=end
