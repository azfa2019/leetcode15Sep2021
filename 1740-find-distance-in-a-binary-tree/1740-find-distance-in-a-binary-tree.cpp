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
    int findDistance(TreeNode* root, int p, int q) {
        TreeNode* g=lca(root,p,q);
        return dfs(g,p)+dfs(g,q);
    }
    TreeNode* lca(TreeNode* root,int p,int q){
        if(!root||root->val==p||root->val==q) return root;
        TreeNode* l=lca(root->left,p,q);
        TreeNode* r=lca(root->right,p,q);
        if(!l) return r;
        if(!r) return l;
        return root;
    }
    int dfs(TreeNode* root,int v){
        if(!root) return -1;
        if(root->val==v) return 0;
        int l=dfs(root->left,v);
        int r=dfs(root->right,v);
        if(l==-1&&r==-1) return -1;
        return 1+max(l,r);
    }
};