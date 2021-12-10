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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int>ans;
        inOrder(root,target,k,ans);
        return ans;
    }
    void inOrder(TreeNode* root,double target,int k,vector<int>&ans){
        if(root==nullptr) return;
        inOrder(root->left,target,k,ans);
        if(ans.size()==k){
            if(abs(target-double(root->val))<abs(target-double(ans[0]))) ans.erase(ans.begin());
            else return;
        }
        ans.push_back(root->val);
        inOrder(root->right,target,k,ans);
    }
};