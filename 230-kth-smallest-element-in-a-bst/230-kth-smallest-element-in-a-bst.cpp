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
    int kthSmallest(TreeNode* root, int k) {
        int l=count(root->left);
        if(k-1<l) return kthSmallest(root->left,k);
        else if(l==k-1) return root->val;
        else return kthSmallest(root->right,k-l-1);
    }
    int count(TreeNode* node){
        if(!node) return 0;
        return count(node->left)+count(node->right)+1;
    }
};