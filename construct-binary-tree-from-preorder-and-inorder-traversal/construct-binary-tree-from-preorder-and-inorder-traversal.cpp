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
    vector<int> preorder;
    vector<int> inorder;
    unordered_map<int,int>mp;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder=preorder;
        this->inorder=inorder;
        int n=preorder.size();
        for(int i=0;i<n;i++) mp[inorder[i]]=i;
        return helper(0,n-1,0,n-1);
    }
    TreeNode* helper(int ps,int pe,int is,int ie ){
        if(ps>pe ||is>ie) return nullptr;
        //if(ps==pe ||is==ie) return new TreeNode(preorder[ps]);
        TreeNode* node=new TreeNode(preorder[ps]);
        int pos=mp[preorder[ps]];
        int llen=pos-is;
        int rlen=ie-pos;
        node->left=helper(ps+1,ps+1+llen-1,is,pos-1);
        node->right=helper(pe-rlen+1,pe,pos+1,ie);
        return node;
    }
};