/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *head=new ListNode(0);
        ListNode *temp = head;

        int carry=0;
        int sum=0;
        while(l1 || l2)
        {
            if( l1 && l2)
            {
                sum = l1->val + l2->val + carry;
                l1=l1->next;
                l2=l2->next;
            }
            else if (l1)
            {
                sum=l1->val + carry;
                l1 = l1->next;
            }
            else
            {
                sum=l2->val+carry;
                l2=l2->next;
            }
            carry = sum >= 10 ? 1:0;
            sum = sum % 10;
            temp ->next = new ListNode(sum);
            temp =temp->next;
        }

        if (carry)
        {
            temp->next = new ListNode(carry);
        }
        return head->next;
    }
};
// @lc code=end

