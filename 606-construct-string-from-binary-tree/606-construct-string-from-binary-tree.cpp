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
    string ans;
    string tree2str(TreeNode* root) {
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* root){
        if(!root) return;
        ans+=to_string(root->val);
        if(root->left||root->right){
            ans+="(";
            dfs(root->left);
            ans+=")";
        }
        if(root->right){
            ans+="(";
            dfs(root->right);
            ans+=")";
        }
    }
};