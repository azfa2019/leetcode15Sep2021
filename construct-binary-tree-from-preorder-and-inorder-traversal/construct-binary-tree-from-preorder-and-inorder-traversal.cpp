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
  unordered_map<int,int>map0;
  vector<int> inorder,preorder;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      this->preorder=preorder;
      this->inorder=inorder;
      for(int i=0;i<inorder.size();i++) map0[inorder[i]]=i;
      return helper(0,preorder.size()-1,0,inorder.size()-1);
    }
  TreeNode* helper(int preStart,int preEnd,int inStart,int inEnd){
    if(preStart>preEnd||inStart>inEnd) return nullptr;
    int rootVal=preorder[preStart];
    int rootPos=map0[rootVal];
    TreeNode* root=new TreeNode(rootVal);
    int leftSize=rootPos-1-inStart;
    //int rightSize=inEnd-rootPos-1-inStart;
    root->left=helper(preStart+1,preStart+1+leftSize,inStart,rootPos-1);
    root->right=helper(preStart+1+leftSize+1,preEnd,rootPos+1,inEnd);
    return root;
  }
};