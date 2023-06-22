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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        vector<int>v1,v2;
        inorder(root1,v1),inorder(root2,v2);
        int p1=0,p2=v2.size()-1;
        while(p1<v1.size() && p2>=0){
            if(v1[p1]+v2[p2]==target) return true;
            else if(v1[p1]+v2[p2]<target) p1++;
            else p2--;
        }
        return false;
    }
    void inorder(TreeNode* root,vector<int>& v){
        if(!root) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
};