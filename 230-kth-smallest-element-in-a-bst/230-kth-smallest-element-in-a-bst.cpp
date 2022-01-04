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
        int l=numNodes(root->left);
        if(l==k-1) return root->val;
        else if(l>k-1) return kthSmallest(root->left,k);
        else return kthSmallest(root->right,k-l-1);
    }
    int numNodes(TreeNode* node){
        if(!node) return 0;
        return numNodes(node->left)+numNodes(node->right)+1;
    }
};