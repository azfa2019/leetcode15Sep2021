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
    void pushLeft(TreeNode* root){
        while(root){
            stk.push(root);
            root=root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    bool hasNext() {
        if(check(index+1)) return true;
        return stk.size();
    }
    
    
    int next() {
        int nextVal;
        if(check(index+1)){
            nextVal=nodes[index+1]->val;
        }else{
            auto next=stk.top();
            stk.pop();
            pushLeft(next->right);
            nodes.push_back(next);
            nextVal=next->val;
        }
        index++;
        return nextVal;
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