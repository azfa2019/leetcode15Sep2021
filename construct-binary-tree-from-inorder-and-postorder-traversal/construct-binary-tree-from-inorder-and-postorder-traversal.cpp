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
  unordered_map<int,int>inPos;
  vector<int> postorder;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      for(int i=0;i<inorder.size();i++) inPos[inorder[i]]=i;
      this->postorder=postorder;
      return helper(0,inorder.size()-1,0,postorder.size()-1);
    }
  TreeNode* helper(int inLeft,int inRight,int postLeft,int postRight){
    if(inLeft>inRight || postLeft>postRight) return nullptr;
    int rootVal=postorder[postRight];
    int rootPos=inPos[rootVal];
    TreeNode* node=new TreeNode(rootVal);
    node->left=helper(inLeft,rootPos-1,postLeft,postLeft+rootPos-inLeft-1);
    node->right=helper(rootPos+1,inRight,postLeft+rootPos-inLeft,postRight-1);
    return node;
  }
};