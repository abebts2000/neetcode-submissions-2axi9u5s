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
    void reorderList(ListNode* head) {
        if (!head) return;
        stack<ListNode*>stk;
        auto temp = head;
        int c =0;
        while(temp)
        {
            stk.push(temp);
            temp = temp->next;
            c++;
        }
        auto temp2 = head;

        c/=2;
        while(c>0)
        {
            auto top = stk.top();
            auto next = temp2->next;
            stk.pop();
            temp2->next = top;
            top->next = next;

            temp2 = next;
            c--;
        }
        temp2->next = nullptr;
    }
};
