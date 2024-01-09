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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>ans1,ans2;
        inorder(root1,ans1),inorder(root2,ans2);
        return ans1==ans2;
    }
    void inorder(TreeNode* root,vector<int>&ans){
        if(root->left) inorder(root->left,ans);
        if(root->left==nullptr && root->right==nullptr) {
            ans.push_back(root->val);
            return;
        }
        if(root->right) inorder(root->right,ans);
    }
};