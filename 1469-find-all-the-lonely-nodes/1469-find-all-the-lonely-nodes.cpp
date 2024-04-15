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
    vector<int>res;
    vector<int> getLonelyNodes(TreeNode* root) {
        dfs(root);
        return res;
    }
    void dfs(TreeNode* node){
        if(!node) return;
        if(!node->left && node->right) {
            res.push_back(node->right->val);
        }
        if(!node->right&&node->left) {
            res.push_back(node->left->val);
        }
        dfs(node->left);
        dfs(node->right);
    }
};