/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        unordered_map<Node*,Node*>hash;
        for(auto p=head;p;p=p->next){
            hash[p]=new Node(p->val);
        }
        for(auto p=head;p;p=p->next){
            hash[p]->next=hash[p->next];
            hash[p]->random=hash[p->random];
        }
        return hash[head];
    }
};