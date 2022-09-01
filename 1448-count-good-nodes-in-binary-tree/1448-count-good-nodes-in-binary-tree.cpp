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
public:
    int res=0;
    int goodNodes(TreeNode* root) {
        dfs(root,INT_MIN);
        return res;
    }
    void helper(TreeNode* root,int max){
        if(!root) return;
        if(root->val>=max){
            max=root->val;
            res++;
        }
        helper(root->left,max);
        helper(root->right,max);
    }
    void dfs(TreeNode *root,int mymax)
    {
        if(root==nullptr)
            return ;
        if(root->val>=mymax)
            res++;
        dfs(root->left,max(mymax,root->val));
        dfs(root->right,max(mymax,root->val));
    }

};