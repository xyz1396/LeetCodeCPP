/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
#include <string>
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
public:
    string convert(string s, int numRows)
    {
        int sLen = s.size();
        if (numRows == 1)
            return s;
        vector<vector<char>> z(numRows, vector<char>(sLen));
        int zRow = 0;
        int zCol = 0;
        if (numRows == 2)
        {
            for (int i = 0; i < sLen; i++)
            {
                z[zRow++][zCol] = s[i];
                if (zRow > 1)
                {
                    zRow = 0;
                    zCol++;
                }
            }
        }
        zRow = 0;
        zCol = 0;
        int count = 1;
        if (numRows > 2)
        {
            for (int i = 0; i < sLen; i++)
            {
                if (count < numRows)
                    z[zRow++][zCol] = s[i];
                else
                    z[zRow--][zCol++] = s[i];
                if (zRow == 0)
                    count = 0;
                count++;
            }
        }
        string newS;
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < sLen; j++)
            {
                if (z[i][j] != '\0')
                    newS += z[i][j];
            }
        }
        return newS;
    }
    string convert2(string s, int numRows)
    {
        if (numRows ==1 || s.size()<=numRows)
            return s;
        vector<string> rows(numRows);
        int curRow =0;
        bool goingDown = false;
        for (char c:s)
        {
            rows[curRow] +=c;
            if (curRow ==0 || curRow ==numRows-1)
                goingDown = !goingDown;
                curRow += goingDown ? 1:-1;
        }
        string ret;
        for (string row: rows)
            ret+=row;
        return ret;
    }
};
// @lc code=end

main()
{
    string a = "PAYPALISHIRING";
    int b = 2;
    Solution s;
    string c = s.convert(a, b);
    cout << c << endl;
    cout << s.convert(a, 3) << endl;
    cout << s.convert2(a, 3) << endl;
}
