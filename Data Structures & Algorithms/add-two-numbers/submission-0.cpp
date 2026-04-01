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
        ListNode* res = new ListNode();
        int carry =0,add =0;
        auto temp = res;
        while(l1 || l2)
        {
            int num1 = l1?l1->val:0;
            int num2 = l2?l2->val:0;

            int sum = num1+num2+carry;
            temp->next = new ListNode(sum%10);
            carry = sum/10;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
            temp = temp->next;
        }
        if(carry%2)
            temp->next = new ListNode(carry);
        return res->next;
    }
};
