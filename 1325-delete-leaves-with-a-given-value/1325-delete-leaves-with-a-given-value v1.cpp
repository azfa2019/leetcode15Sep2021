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
    int target;
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        this->target=target;
        return helper(root);
    }
    TreeNode* helper(TreeNode* node){
        if(!node) return nullptr;
        auto left=helper(node->left);
        auto right=helper(node->right);
        node->left=left;
        node->right=right;
        if(!node->left && !node->right && node->val==target) return nullptr; 
        return node;
    }
};
