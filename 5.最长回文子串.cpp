/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s)
    {
        string newStr = "$#";
        for (int i = 0; i < s.length(); i++)
        {
            newStr += s[i];
            newStr += "#";
        }
        vector<int> Len(newStr.length(), 0);
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

