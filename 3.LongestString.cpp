/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> m;
        int ans = 0;
        int n = s.size();
        int i = 0;
        for (int j = 0; j < n; j++)
        {
            // find with return end iterator if not found
            if (m.find(s[j]) != m.end())
                //  skip repeat substring's start point
                i = max(m.find(s[j])->second + 1, i);
            ans = max(ans, j - i + 1);
            m[s[j]] = j;
        }
        return ans;
    }
    int lengthOfLongestSubstring2(string s)
    {
        unordered_map<char, int> m;
        int ans = 0;
        int n = s.size();
        int i = 0;
        for (int j = 0; j < n; j++)
        {
            if (m.count(s[j]))
                //  skip repeat substring's start point
                i = max(m[s[j]] + 1, i);
            ans = max(ans, j - i + 1);
            m[s[j]] = j;
        }
        return ans;
    }
};
// @lc code=end

int main()
{
    Solution s;
    string a = "523335678";
    printf("%d \n", s.lengthOfLongestSubstring(a));
    printf("%d \n", s.lengthOfLongestSubstring2(a));
}