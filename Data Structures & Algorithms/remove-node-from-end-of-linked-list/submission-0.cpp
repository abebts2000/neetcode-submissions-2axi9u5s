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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*node = new ListNode();
        node->next= head;
        auto temp1 = node;
        auto temp2 = node;

        while(n>0 && temp2)
        {
            temp2 = temp2->next;
            n--;
        }
        if(n>0)
            return head;
        while(temp2->next)
        {
            temp2=temp2->next;
            temp1 = temp1->next;
        }
        temp1->next = temp1->next->next;
        return node->next;
    }
};
