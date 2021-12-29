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
    int ans;
public:
    int longestConsecutive(TreeNode* root) {
        return dfs(root,nullptr,0);
    }
    int dfs(TreeNode* node,TreeNode* parent,int len){
        if(!node) return len;
        len=(parent && node->val==parent->val+1)?len+1:1;
        return max(len,max(dfs(node->left,node,len),dfs(node->right,node,len)));
    }
};
