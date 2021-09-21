/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x)
    {
        int flag=x<0?-1:1;
        int num=0;
        while(x)
        {
            if ((flag==-1 && (INT32_MIN/10>num))||
            (flag==1 && INT32_MAX/10 < num))
                return 0;
            num=num*10+x%10;
            x/=10;
        }
        return num;
    }
};
// @lc code=end

