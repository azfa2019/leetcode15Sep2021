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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int>ans;
        stack<TreeNode*>stck;
        stck.push(root);
        while(!stck.empty()){
            auto cur=stck.top();stck.pop();
            ans.push_back(cur->val);
            if(cur->right) stck.push(cur->right);
            if(cur->left) stck.push(cur->left);
        }
        return ans;
    }
};