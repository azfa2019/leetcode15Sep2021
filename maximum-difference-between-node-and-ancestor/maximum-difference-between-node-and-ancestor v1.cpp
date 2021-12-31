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
    int ans=INT_MIN;
public:
    int maxAncestorDiff(TreeNode* root) {
        helper(root,root->val,root->val);
        return ans;
    }
    void helper(TreeNode* node,int maxVal,int minVal){
        if(!node) return;
        maxVal=max(maxVal,node->val);
        minVal=min(minVal,node->val);
        ans=max(ans,abs(maxVal-minVal));
        helper(node->left,maxVal,minVal);
        helper(node->right,maxVal,minVal);
    }
};
