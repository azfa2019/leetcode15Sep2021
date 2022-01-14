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
    int ans=0;
    public:
    int longestZigZag(TreeNode* root) {
        auto res=dfs(root,0);
        return ans-1;
    }
    int dfs(TreeNode* node,int dir){
        if(!node) return 0;
        auto l=dfs(node->left,0)+1;
        auto r=dfs(node->right,1)+1;
        int tmp=max(l,r);
        ans=max(ans,tmp);
        return dir==0?r:l;
    }
};