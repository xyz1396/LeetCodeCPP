/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int count = nums.size();
        vector<int> ix;
        for (int i = 0; i < count; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (nums[j] == target - nums[i])
                {
                    ix.push_back(i);
                    ix.push_back(j);
                }
            }
            if (ix.size() == 2)
                break;
        }
        return ix;
    }

    vector<int> twoSum2(vector<int> &nums, int target)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (m.count(target - nums[i]))
                return {m[target - nums[i]], i};
            m[nums[i]] = i;
        }
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> nums{2, 7, 11, 15};
    int target = 9;
    vector<int> result = s.twoSum(nums, target);
    printf("[%d, %d]", result[0], result[1]);
}
