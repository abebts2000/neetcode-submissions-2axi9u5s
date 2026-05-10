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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }

        ListNode* cur = prev->next;
        for (int i = 0; i < right - left; i++) {
            ListNode* nextNode = cur->next;
            cur->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;


        }
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};