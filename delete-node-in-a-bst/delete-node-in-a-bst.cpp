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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return nullptr;
        if(key<root->val) root->left=deleteNode(root->left,key);
        else if(key>root->val) root->right=deleteNode(root->right,key);
        else{
            if(root->left==nullptr && root->right==nullptr) return nullptr;
            else if(root->right!=nullptr) {
                root->val=successor(root);
                root->right=deleteNode(root->right,root->val);
            }else if(root->left!=nullptr){
                root->val=predecessor(root);
                root->left=deleteNode(root->left,root->val);
            }
        }
        return root;
    }
    int successor(TreeNode* node){
        node=node->right;
        while(node->left) node=node->left;
        return node->val;
    }
    int predecessor(TreeNode* node){
        node=node->left;
        while(node->right) node=node->right;
        return node->val;
    }
};