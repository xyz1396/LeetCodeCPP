/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// Manacher algorithm https://blog.csdn.net/dyx404514/article/details/42061017
// https://blog.csdn.net/qq_38279908/article/details/88344758

// @lc code=start
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int size = s.size();
        vector<vector<bool>> dp(size, vector<bool>(size, false));
        int start = 0;
        int maxLength = 1;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (i - j < 2)
                    dp[j][i] = (s[j] == s[i]);
                else
                    dp[j][i] = (s[j] == s[i]) && (dp[j + 1][i - 1]);
                if (dp[j][i] && maxLength < i - j + 1)
                {
                    maxLength = i - j + 1;
                    start = j;
                }
            }
        }
        return s.substr(start, maxLength);
    }

    string longestPalindrome2(string s)
    {
        string newStr = "$#";
        for (int i = 0; i < s.length(); i++)
        {
            newStr += s[i];
            newStr += "#";
        }
        vector<int> Len(newStr.length(), 0);
        // pos is last max palindrome's central index
        // mx is the right index 
        int pos = 0, mx = 0;
        int start = 0, maxLen = 0;
        for (int i = 1; i < newStr.size(); i++)
        {
            Len[i] = i < mx ? min(Len[2 * pos - i], mx - i) : 1;
            while (i + Len[i] < newStr.size() &&
                   i - Len[i] > 0 &&
                   newStr[i + Len[i]] == newStr[i - Len[i]])
                Len[i]++;
            if (i + Len[i] > mx)
            {
                pos = i;
                mx = i + Len[i];
            }
            if (Len[i] - 1 > maxLen)
            {
                start = (i - Len[i]) / 2;
                maxLen = Len[i] - 1;
            }
        }
        return s.substr(start, maxLen);
    }
};
// @lc code=end

main()
{
    Solution s;
    string b = "babad";
    printf("%s\n", b.c_str());
    printf("%s\n", s.longestPalindrome(b).c_str());
    printf("%s\n", s.longestPalindrome2(b).c_str());
}