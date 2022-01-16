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
        unordered_map<int,int>mp;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++) mp[inorder[i]]=i;
        return helper(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int preS,int preE,int inS, int inE){
        if(preS>preE || inS>inE) return nullptr;
        if(preS==preE || inS==inE) return new TreeNode(preorder[preS]);
        TreeNode* cur=new TreeNode(preorder[preS]);
        int pos=mp[preorder[preS]];
        int lenLeft=pos-inS;
        int lenRight=inE-(pos+1)+1;
        cur->left=helper(preorder,inorder,preS+1,preS+1+lenLeft-1,inS,pos-1);
        cur->right=helper(preorder,inorder,preE-lenRight+1,preE,pos+1,inE);
        return cur;
    }
};
// pre: preS xxxx | xxxx preE, 
//inorder: inS xxxx pos xxxx inE