/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = p.length() + 1;
        int n = s.length() + 1;
        bool **dp = NULL;
        dp = new bool *[m];
        for (int i = 0; i < m; i++)
        {
            dp[i] = new bool[n];
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // for empty pattern head
                if (i == 0)
                {
                    if (j == 0)
                        dp[i][j] = true;
                    else
                        dp[i][j] = false;
                }
                // for empty string head
                else if (j == 0)
                {
                    if (p[i - 1] != '*')
                        dp[i][j] = false;
                    // for pattern like a*b*c*
                    else
                        // dp[1 - 1][0] is true, dp[1 - 2][0] won't be calculated
                        dp[i][j] = dp[i - 1][j] || dp[i - 2][j];
                }
                else
                {
                    if (p[i - 1] == '.')
                        dp[i][j] = dp[i - 1][j - 1];
                    else if (p[i - 1] == '*')
                    {
                        // first char of pattern is *
                        if (i == 1)
                            dp[i][j] = false;
                        else
                            dp[i][j] = dp[i - 2][j] || dp[i - 1][j] ||
                                       (dp[i][j - 1] && (p[i - 2] == '.' || p[i-2] == s[j-1]));
                    }
                    else
                        dp[i][j] = ((s[j - 1] == p[i - 1]) && dp[i - 1][j - 1]);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end

