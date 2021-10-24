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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode *curr = new ListNode(-1);
        ListNode *v = curr;
        while(l1 && l2)
        {
            int a = l1->val +l2->val + carry;
            if(a>=10)
            {
                carry = 1;
                a %=10;
            }
            else
                carry=0;
            ListNode *x = new ListNode(a);
            curr->next = x;
            curr = curr->next;
            l1 = l1->next;
            l2 = l2 ->next;
        }
        if(l1)
        {
            while(l1)
            {
                 int a = l1->val + carry;
                if(a>=10)
                {
                    carry = 1;
                    a %=10;
                }
                else
                    carry=0;
                ListNode *x = new ListNode(a);
                 curr->next = x;
                curr = curr->next;
                l1 = l1->next;
            }
        }
        if(l2)
        {
            while(l2)
            {
                 int a = l2->val + carry;
                if(a>=10)
                {
                    carry = 1;
                    a %=10;
                }
                else
                    carry=0;
                ListNode *x = new ListNode(a);
                 curr->next = x;
                curr = curr->next;
                l2 = l2->next;
            }
        }
        if(carry)
        {
            ListNode *x = new ListNode(1);
            curr->next = x;
        }
        return v->next;
    }
};
