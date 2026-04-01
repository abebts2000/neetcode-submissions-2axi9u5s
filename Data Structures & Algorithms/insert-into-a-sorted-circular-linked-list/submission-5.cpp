/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        auto temp = head;

        Node*node = new Node(insertVal);
        if(!temp)
            return node;
        while(temp->next != head)
        {
            if((temp->val <= insertVal && temp->next->val >= insertVal))
            {
               
                node->next = temp->next;
                temp->next = node;
                return node;
            }
            else if(temp->val > temp->next->val && (insertVal >= temp->val || insertVal <= temp->next->val) )
            {
                node->next = temp->next;
                temp->next = node;
                return node;
            }
            temp = temp->next;
        }
        temp->next = node;
        node->next=head;
        return node;
    }
};
