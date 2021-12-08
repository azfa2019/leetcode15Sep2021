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
    vector<int>ans;
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return{};
        if(root->left || root->right) ans.push_back(root->val);
        leftboundary(root->left);
        leaf(root);
        rightboundary(root->right);
        return ans;
    }
    void leftboundary(TreeNode* node){
        if(!node) return;
        if(!node->left && !node->right) return;
        ans.push_back(node->val);
        if(node->left) leftboundary(node->left);
        else leftboundary(node->right);
    }
    void rightboundary(TreeNode* node){
        if(!node) return;
        if(!node->left && !node->right) return;
        if(node->right) rightboundary(node->right);
        else rightboundary(node->left);
        ans.push_back(node->val);
    }
    void leaf(TreeNode* node){
        if(!node) return;
        if(!node->left && !node->right) ans.push_back(node->val);
        leaf(node->left);
        leaf(node->right);
    }
};