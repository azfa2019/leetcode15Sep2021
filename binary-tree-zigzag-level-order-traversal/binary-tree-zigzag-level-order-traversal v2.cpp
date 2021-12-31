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
    vector<vector<int>>ans;
    public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        dfs(0,root);
        return ans;
    }
    void dfs(int idx,TreeNode* root){
        if(root==nullptr) return;
        if(idx==ans.size()) ans.push_back({});
        if(idx%2==0)
            ans[idx].push_back(root->val);
        else ans[idx].insert(ans[idx].begin(),root->val);
        dfs(idx+1,root->left);
        dfs(idx+1,root->right);
    }
};
