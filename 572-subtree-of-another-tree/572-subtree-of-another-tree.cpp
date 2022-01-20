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
        if(!root || !subRoot) return root==subRoot;
        return isSame(root,subRoot) || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
    bool isSame(TreeNode* n1, TreeNode* n2){
        if(!n1 || !n2) return n1==n2;
        return n1->val==n2->val && isSame(n1->left,n2->left) && isSame(n1->right,n2->right);
    }
};