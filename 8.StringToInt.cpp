/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include <string>
#include <iostream>
using namespace std;
class Solution
{
public:
    int myAtoi(string s)
    {
        int ret = 0;
        int flagNeg = 1;
        bool isFirst = true;
        bool overflowed = false;
        for (char c : s)
        {
            int tmp = (int)c;
            if (isFirst)
            {
                if (tmp == 32)
                    continue;
                if (tmp == 45)
                    flagNeg = -1;
                else if (tmp == 43)
                    ;
                else if (tmp >= 48 && tmp <= 57)
                    ret = tmp - 48;
                else
                    break;
                isFirst = false;
            }
            else
            {
                if (tmp >= 48 && tmp <= 57)
                {
                    if (ret < INT_MAX / 10)
                        ret = ret * 10 + (tmp - 48);
                    else if (ret == INT_MAX / 10)
                    {
                        if (tmp - 48 <= 7)
                            ret = ret * 10 + (tmp - 48);
                        else
                        {
                            ret = INT_MAX;
                            overflowed = true;
                        }
                    }
                    else
                    {
                        ret = INT_MAX;
                        overflowed = true;
                    }
                }
                else
                    break;
            }
        }
        if (flagNeg == -1 && ret == INT_MAX && overflowed == true)
            return INT_MIN;
        else
            return ret * flagNeg;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    string a = "   -4193 with - words";
    cout << s.myAtoi(a) << endl;
    cout << s.myAtoi("-91283472332") << endl;
    cout << s.myAtoi("  91283472332") << endl;
    cout << INT_MIN << endl;
    cout << s.myAtoi("3.14") << endl;
    cout << s.myAtoi("+-12") << endl;
    cout << s.myAtoi("  0000000000012345678") << endl;
    cout << s.myAtoi("words and 987") << endl;
    cout << s.myAtoi("  +0 123") << endl;
    cout << s.myAtoi("2147483646") << endl;
    cout << s.myAtoi("21474836460") << endl;
    cout << s.myAtoi("-2147483647") << endl;
    cout << INT_MIN << " " << INT_MAX * -1 << endl;
    return 0;
}
