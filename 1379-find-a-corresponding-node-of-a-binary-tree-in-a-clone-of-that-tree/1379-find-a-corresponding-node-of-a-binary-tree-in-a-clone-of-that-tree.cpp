/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* res;
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        inorder(cloned,target);
        return res;
    }
    void inorder(TreeNode* root,TreeNode* target){
        if(!root) return;
        inorder(root->left,target);
        if(root->val==target->val) res=root;
        inorder(root->right,target);
    }
};