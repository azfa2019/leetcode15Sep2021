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
        auto res=dfs(root);
        return ans-1;
    }
    pair<int,int> dfs(TreeNode* node){
        if(!node) return {0,0};
        auto l=dfs(node->left);
        auto r=dfs(node->right);
        int curL=l.second+1;
        int curR=r.first+1;
        int tmp=max(curL,curR);
        ans=max(ans,tmp);
        return {curL,curR};
    }
};