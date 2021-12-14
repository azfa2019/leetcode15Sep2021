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
        int n=preorder.size();
        this->preorder=preorder;
        this->inorder=inorder;
        for(int i=0;i<inorder.size();i++) mp[inorder[i]]=i;
        return build(0,n-1,0,n-1);
    }
    TreeNode* build(int sPre,int ePre,int sIn,int eIn){
        if(sPre>ePre || sIn>eIn) return nullptr;
        //if(sPre==ePre && sIn==eIn) {
        //    TreeNode* node=new TreeNode(inorder[sPre]);
        //    return node;
        //}
        int val=preorder[sPre];
        int pos=mp[val];
        TreeNode* root=new TreeNode(val);
        int len1=pos-1-sIn,len2=eIn-(pos+1);
        root->left=build(sPre+1,sPre+1+len1,sIn,pos-1);
        root->right=build(ePre-len2,ePre,pos+1,eIn);
        return root;
    }
};