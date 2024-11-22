/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
  public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const int sLen = s.length();
        vector<bool> startPoints(sLen + 1,
                                 false);  // 可以從哪個位置開始找新單字
        startPoints[0] = true;            // 一定有 0 (從頭找)
        for (int i = 1; i <= sLen; i++) {
            //           s :   w e a p p l e
            // startPoints : T F T F F F
            //                         ^ (i = 5)
            //                   <-----|  1. 用 for 迴圈尋訪字典
            //                               先檢查長度是否合法 (i - len(某單字)
            //                               >= 0) 再檢查 startPoints[i -
            //                               len(某單字)] 是否為 T
            //                            2. 如果長度剛好，比較 s[i -
            //                            len(某單字)] ~ s[i]
            //                               是否與該單字相同
            for (string word : wordDict) {
                const int wLen = word.length();
                if (i - wLen >= 0 && startPoints[i - wLen] &&
                    s.substr(i - wLen, wLen) == word) {
                    startPoints[i] = true;
                    break;
                }
            }
        }

        return startPoints[sLen];
    }
};
// @lc code=end
