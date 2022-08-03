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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>>res;
        if(!root) return {};
        helper(root,res);
        return res;
    }
    int helper(TreeNode* root,vector<vector<int>>&res){
        if(!root) return -1;
        int l=helper(root->left,res);
        int r=helper(root->right,res);
        int d=max(l,r)+1;
        if(res.size()<d+1) res.push_back({});
        res[d].push_back(root->val);
        return d;
    }
};