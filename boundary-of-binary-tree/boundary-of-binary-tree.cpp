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
        if(root==nullptr) return {};
        if(root->left!=nullptr || root->right!=nullptr) ans.push_back(root->val);
        lhelper(root->left);
        leaf(root);
        rhelper(root->right);
        return ans;
    }
    void lhelper(TreeNode* node){
        if(node==nullptr) return;
        if(node->left==nullptr && node->right==nullptr) return;
        ans.push_back(node->val);
        if(node->left!=nullptr) lhelper(node->left);
        else lhelper(node->right);
    }
    void rhelper(TreeNode* node){
        if(node==nullptr) return;
        if(node->left==nullptr && node->right==nullptr) return;
        if(node->right==nullptr) rhelper(node->left);
        else rhelper(node->right);
        ans.push_back(node->val);
    }
    void leaf(TreeNode* node){
        if(node==nullptr) return;
        if(node->left==nullptr && node->right==nullptr) ans.push_back(node->val);
        leaf(node->left);
        leaf(node->right);
    }
};
//   1
//    4
//. 3  
// 2 
//5