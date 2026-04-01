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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](const ListNode*a, const ListNode*b)
        {
            return a->val > b->val;
        };
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)>pq(cmp);
        ListNode* ans = new ListNode(0);
        for(int i =0;i<lists.size();i++)
        {
            pq.push(lists[i]);
        }
        auto tail = ans;
        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            if(top->next)
                pq.push(top->next);
            tail->next = top;
            tail = tail->next;
        }
        return ans->next;
    }
};
