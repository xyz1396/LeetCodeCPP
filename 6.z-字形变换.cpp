/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows)
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

