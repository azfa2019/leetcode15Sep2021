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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>stck;
        if(!root) return {};
        stck.push(root);
        while(!stck.empty()){
            auto cur=stck.top();stck.pop();
            ans.push_back(cur->val);
            if(cur->left!=nullptr) stck.push(cur->left);
            if(cur->right!=nullptr) stck.push(cur->right);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};