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
    int ans;
public:
    int largestBSTSubtree(TreeNode* root) {
        ans=0;
        dfs(root);
        return ans;
    }
    vector<int>dfs(TreeNode* root){
        if(!root) return {INT_MAX,INT_MIN,0};
        auto l=dfs(root->left);
        auto r=dfs(root->right);
        if(l[2]==-1 || r[2]==-1) return {INT_MIN,INT_MAX,-1};
        else if(root->val>l[1] && root->val<r[0]) {
            int count=l[2]+r[2]+1;
            ans=max(ans,count);
            int low=l[0]==INT_MAX?root->val:l[0];
            int high=r[1]==INT_MIN?root->val:r[1];
            return {low,high,count};
        }else return {INT_MIN,INT_MAX,-1};
    }
};