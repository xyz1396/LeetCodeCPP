/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x)
    {
        int rev = 0;
        int ori = x;
        if (x < 0)
            return false;
        else
        {
            while (x > 0)
            {
                if (rev > INT_MAX / 10)
                    return false;
                rev = rev * 10 + x % 10;
                x /= 10;
            }
            if (rev == ori)
                return true;
            else
                return false;
        }
    }
};
// @lc code=end

