/*
 * @lc app=leetcode id=1630 lang=cpp
 *
 * [1630] Arithmetic Subarrays
 */

// @lc code=start
class Solution {
  public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l,
                                          vector<int>& r) {
        vector<bool> ans;
        for (int i = 0; i < l.size(); i++) {
            vector<int> v;
            for (int j = l[i]; j <= r[i]; j++) {
                auto it = v.begin();
                while (it != v.end()) {
                    if (*it > nums[j]) {
                        v.insert(it, nums[j]);
                        break;
                    }
                    it++;
                }
                if (it == v.end()) v.push_back(nums[j]);
            }
            sort(v.begin(), v.end());
            auto it = v.begin();
            int d = *(it + 1) - *it;
            bool status = true;
            it++;
            while (it + 1 < v.end()) {
                if (*(it + 1) - *it != d) {
                    status = false;
                    break;
                }
                it++;
            }
            ans.push_back(status);
        }

        return ans;
    }
};
// @lc code=end
