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
class Solution {
    TreeNode* tail;
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy=new TreeNode();
        tail=dummy;
        dfs(root);
        return dummy->right;
    }
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        root->left=nullptr;
        tail=tail->right=root;
        dfs(root->right);
    }
};