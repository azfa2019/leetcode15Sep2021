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
    stack<TreeNode*>stck;
    public:
    BSTIterator(TreeNode* root) {
        TreeNode* node=root;
        while(node!=nullptr) {
            stck.push(node);
            node=node->left;
        }
    }

    int next() {
        int ans=stck.top()->val;
        TreeNode* node=stck.top()->right;
        stck.pop();
        while(node!=nullptr) {
            stck.push(node);
            node=node->left;
        }
        return ans;        
    }

    bool hasNext() {
        return !stck.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
