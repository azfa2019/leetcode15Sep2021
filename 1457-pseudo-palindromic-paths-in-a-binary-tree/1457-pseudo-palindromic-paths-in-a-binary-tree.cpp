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
    int ans=0;
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root) return 0;
        int num=0;
        dfs(root,num);
        return ans;
    }
    void dfs(TreeNode* root,int tmp){
        int n=tmp^(1<<root->val);
        if(!root->left&&!root->right){
            if(n==0||(n&(n-1))==0) ans++;
            return;
        }
        if(root->left) dfs(root->left,n);
        if(root->right) dfs(root->right,n);
    }
};