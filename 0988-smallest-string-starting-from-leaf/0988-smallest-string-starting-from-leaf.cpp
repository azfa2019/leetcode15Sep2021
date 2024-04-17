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
    string ans,path;
    string smallestFromLeaf(TreeNode* root) {
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* node){
        if(!node) return;
        path+=node->val+'a';
        if(!node->left && !node->right){
            reverse(path.begin(),path.end());
            if(ans.empty()||ans>path) ans=path;
            reverse(path.begin(),path.end());
        }else{
            dfs(node->left);
            dfs(node->right);
        }
        path.pop_back();
    }
};