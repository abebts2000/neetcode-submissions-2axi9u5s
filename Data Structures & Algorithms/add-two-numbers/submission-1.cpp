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
    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        auto temp1 = l1, temp2=l2;
        int len1 =0, len2=0;
        while(temp1)
        {
            len1++;
            temp1=temp1->next;
        }

        while(temp2)
        {
            len2++;
            temp2=temp2->next;
        }

        int carry =0,add =0;
        auto head = len1>=len2?l1:l2;
        auto temp = head;
        ListNode*prev = nullptr;
        while(l1 || l2)
        {
            int num1 = l1?l1->val:0;
            int num2 = l2?l2->val:0;

            int sum = num1+num2+carry;
            temp->val =sum%10;
            carry = sum/10;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
            prev = temp;
            temp = temp->next;
        }
        if(carry%2)
            prev->next = new ListNode(carry);
        return head;
    }
};
