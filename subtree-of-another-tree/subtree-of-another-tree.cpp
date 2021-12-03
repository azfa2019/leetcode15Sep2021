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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr || subRoot==nullptr) return root==subRoot;
        //return isSameTree(root,subRoot) || isSameTree(root->left,subRoot) ||isSameTree(root->right,subRoot);
        return isSameTree(root,subRoot) || isSubtree(root->left,subRoot) ||isSubtree(root->right,subRoot);
    }
    bool isSameTree(TreeNode* node1,TreeNode* node2){
        if(node1==nullptr || node2==nullptr) return node1==node2;
        return (node1->val==node2->val) && isSameTree(node1->left,node2->left) && isSameTree(node1->right,node2->right); 
    }
};