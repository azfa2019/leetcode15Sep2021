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
    int maxlen=0;
public:
    int longestConsecutive(TreeNode* root) {
        dfs(root);
        return maxlen;
    }
    vector<int> dfs(TreeNode* root){
        if(!root) return {0,0};
        int inc=1,dec=1;
        auto l=dfs(root->left),r=dfs(root->right);
        if(root->left){
            if(root->left->val-1==root->val) inc=max(inc,l[0]+1);
            if(root->left->val+1==root->val) dec=max(dec,l[1]+1);
        }
        if(root->right){
            if(root->right->val-1==root->val) inc=max(inc,r[0]+1);
            if(root->right->val+1==root->val) dec=max(dec,r[1]+1);
        }
        maxlen=max(maxlen,dec+inc-1);
        return {inc,dec};
    }
};