/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// https://blog.csdn.net/qq_32523711/article/details/107708705

#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays1(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size() + nums2.size();
        vector<int> a(n, 0);
        int i = 0, j = 0, k = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
                a[k++] = nums1[i++];
            else
                a[k++] = nums2[j++];
        }
        while (i < nums1.size())
            a[k++] = nums1[i++];
        while (j < nums2.size())
            a[k++] = nums2[j++];
        if (n % 2)
            return a[n / 2];
        else
            return (a[n / 2] + a[n / 2 - 1]) * 0.5;
    }

    double findMedianSortedArrays2(vector<int> &nums1, vector<int> &nums2)
    {
        int len = nums1.size() + nums2.size();
        int pre = 0, cur = 0;
        int a = 0, b = 0;
        for (int i = 0; i <= len / 2; ++i)
        {
            pre = cur;
            if (a < nums1.size() && (b >= nums2.size() || nums1[a] < nums2[b]))
                cur = nums1[a++];
            else
                cur = nums2[b++];
        }
        if (len % 2)
            return cur;
        else
            return (pre + cur) * 0.5;
    }

    int getKthElement(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int m = nums1.size(), n = nums2.size();
        int index1 = 0, index2 = 0;
        while (true)
        {
            if (index1 == m)
                return nums2[index2 + k - 1];
            if (index2 == n)
                return nums1[index1 + k - 1];
            if (k == 1)
                return min(nums1[index1], nums2[index2]);
            int newIndex1 = min(index1 + k / 2 - 1, m - 1);
            int newIndex2 = min(index2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];
            if (pivot1 <= pivot2)
            {
                // k = k - (newIndex1 - index1 + 1);
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }
            else
            {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }

    double findMedianSortedArrays3(vector<int> &nums1, vector<int> &nums2)
    {
        int len = nums1.size() + nums2.size();
        if (len % 2)
            return getKthElement(nums1, nums2, (len + 1) / 2);
        else
            // use (float) to convert divide or use *0.5
            return (float)(getKthElement(nums1, nums2, len / 2) + getKthElement(nums1, nums2, len / 2 + 1)) / 2;
    }
};
// @lc code=end

main()
{
    Solution s;
    vector<int> a{1, 2};
    vector<int> b{3, 4};
    double result = s.findMedianSortedArrays1(a, b);
    printf("%.2f\n", result);
    result = s.findMedianSortedArrays2(a, b);
    printf("%.2f\n", result);
    result = s.findMedianSortedArrays3(a, b);
    printf("%.2f\n", result);
    int k = 3;
    k -= 3 + 3;
    printf("%d\n", k);
    k = 3;
    k = k - 1 + 2;
    printf("%d\n", k);
}
