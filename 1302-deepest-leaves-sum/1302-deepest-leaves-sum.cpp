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
    //int d=0;
    int maxL=0,sum=0;
    void dfs(TreeNode* root,int level){
        if(!root) return;
        if(level==maxL) sum+=root->val;
        if(level>maxL) sum=root->val,maxL=level;
        dfs(root->left,level+1),dfs(root->right,level+1);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        dfs(root,0);
        return sum;
    }
};