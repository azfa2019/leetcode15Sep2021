/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if(!node) return nullptr;
        Node* res;
        if(node->right){
            res=node->right;
            while(res&& res->left) res=res->left;
        }else{
            res=node->parent;
            while(res&&res->val<node->val) res=res->parent;
        }
        return res;
    }
};