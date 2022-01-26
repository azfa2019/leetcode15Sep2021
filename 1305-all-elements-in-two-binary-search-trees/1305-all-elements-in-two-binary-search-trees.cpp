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
    vector<int>ans;
    public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>v1;
        inorder(root1,v1);
        vector<int>v2;
        inorder(root2,v2);
        int i=0,j=0;
        vector<int>ans;
        while(i<v1.size() && j<v2.size()){
            if(v1[i]<v2[j]) ans.push_back(v1[i++]);
            else ans.push_back(v2[j++]);
        }
        while(i<v1.size()) ans.push_back(v1[i++]);
        while(j<v2.size()) ans.push_back(v2[j++]);
        return ans;
    }
    void inorder(TreeNode* n,vector<int>&ans){
        if(!n) return;
        inorder(n->left,ans);
        ans.push_back(n->val);
        inorder(n->right,ans);
    }
};