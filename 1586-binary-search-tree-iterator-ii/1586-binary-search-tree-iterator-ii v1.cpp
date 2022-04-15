/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*>stk;
    vector<TreeNode*>nodes;
    int index=-1;
public:
    bool check(int i){
        return i>=0 && i<nodes.size();
    }
    
    BSTIterator(TreeNode* root) {
        while(root){
            stk.push(root);
            root=root->left;
        }
    }
    
    bool hasNext() {
        return check(index+1)||stk.size();
    }
    
    int next() {
        index++;
        if(check(index)) return nodes[index]->val;
        auto root=stk.top(),next=root->right;
        stk.pop();
        nodes.push_back(root);
        while(next){
            stk.push(next);
            next=next->left;
        }
        return root->val;
        
    }
    
    bool hasPrev() {
        return check(index-1);
    }
    
    int prev() {
        return nodes[--index]->val;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */
