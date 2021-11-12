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
      return to_string(root->val)+" "+serialize(root->left)+" "+" "+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
      return buildtree(ss);
    }
  TreeNode* buildtree(stringstream& ss){
    string tmp;
    ss>>tmp;
    if(tmp=="#") return nullptr;
    TreeNode* root=new TreeNode(stoi(tmp));
    root->left=buildtree(ss);
    root->right=buildtree(ss);
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;