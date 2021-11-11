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
    //string s= serialize(root->left)+" "+serialize(root->right)+" "+to_string(root->val);
    //cout<<s<<endl;
    return to_string(root->val)+" "+serialize(root->left)+" "+serialize(root->right);
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    stringstream ss(data);
    return buildTree(ss,INT_MIN,INT_MAX);
  }
  TreeNode* buildTree(stringstream& ss,int minVal,int maxVal){
    string word;
    ss>>word;
    if(word=="#") return nullptr;
    int cur=stoi(word);
    if(cur<minVal||cur>maxVal) return nullptr;
    TreeNode* root=new TreeNode(cur);
    root->left=buildTree(ss,minVal,cur);
    root->right=buildTree(ss,cur,maxVal);
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;