/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
  public:

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if(root==nullptr) return "#";
    string left=serialize(root->left);
    string right=serialize(root->right);
    return to_string(root->val)+" "+left+" "+right;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    stringstream ss(data);
    return helper(ss);
  }
  TreeNode* helper(stringstream& ss){
    string tmp;
    ss>>tmp;
    if(tmp=="#") return nullptr;
    TreeNode* root= new TreeNode(stoi(tmp));
    root->left=helper(ss);
    root->right=helper(ss);
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));