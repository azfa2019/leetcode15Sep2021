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
        if(!root) return 0;
        dfs(root,0,root->val);
        return ans;
    }
    void dfs(TreeNode* node,int count,int target){
        if(!node) return;
        if(node->val==target) {
            count++;
            ans=max(ans,count);
        }else count=1;
        dfs(node->left,count,node->val+1);
        dfs(node->right,count,node->val+1);
    }
};