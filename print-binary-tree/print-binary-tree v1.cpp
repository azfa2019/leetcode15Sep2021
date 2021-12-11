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
    vector<vector<string>> printTree(TreeNode* root) {
        int h=height(root);
        int w=(1<<h)-1;
        vector<vector<string>>ans(h,vector<string>(w));
        fill(root,0,0,w-1,ans);
        return ans;
    }
    void fill (TreeNode* root,int h,int left,int right,vector<vector<string>>&ans){
        if(root==nullptr) return;
        int mid=left+(right-left)/2;
        ans[h][mid]=to_string(root->val);
        fill(root->left,h+1,left,mid-1,ans);
        fill(root->right,h+1,mid+1,right,ans);
    }
    int height(TreeNode* node){
        if(node==nullptr) return 0;
        return max(height(node->left),height(node->right))+1;
    }
};
