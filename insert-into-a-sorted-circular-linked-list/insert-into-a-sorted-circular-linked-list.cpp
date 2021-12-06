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
        if(head==nullptr) {
            Node* node=new Node(insertVal);
            node->next=node;
            return node;
        }
        Node* node=head;
        while(node->next!=head){
            if(node->val<=node->next->val){
                if(insertVal>=node->val && insertVal<=node->next->val) break;
            }else{
                if(insertVal>=node->val || insertVal<=node->next->val) break;
            }
            node=node->next;
        }
        Node* next=node->next;
        node->next=new Node(insertVal,next);
        return head;
    }
};