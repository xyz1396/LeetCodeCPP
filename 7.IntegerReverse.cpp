/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
#include <string>
#include <iostream>
using namespace std;

// @lc code=start
class Solution
{
public:
// cannot work on leetcode
    int reverse(int x)
    {
        bool isNeg = false;
        if (x < 0)
        {
            x = -x;
            isNeg = true;
        }
        string s = to_string(x);
        string newS;
        for (char c : s)
        {
            newS = c + newS;
        }
        // string to int
        char* endS;
        x=strtol(newS.c_str(),&endS,10);
        // if newS > 2**31
        if(x==2147483647)
            return 0;
        if (isNeg)
            x = -x;
        return x;
    }

    int reverse2(int x)
    {
        int flag=x<0?-1:1;
        int num=0;
        while(x)
        {
            if ((flag==-1 && (INT_MIN/10>num))||
            (flag==1 && INT_MAX/10 < num))
                return 0;
            num=num*10+x%10;
            x/=10;
        }
        return num;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.reverse(-1534236469) << endl;
    cout << s.reverse(-123) << endl;
    cout << s.reverse2(-1534236469) << endl;
    int i;
    // sscanf can not deal with overflow
    sscanf("6534236469","%d",&i);
    cout<<i<<endl; // 
    return 0;
}
