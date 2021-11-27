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
    string ans;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
      TreeNode* cur=q.front();q.pop();
      if(cur==nullptr) ans+="# ";
      else{
        string nodeval=to_string(cur->val)+" ";
        ans+=nodeval;
        q.push(cur->left);
        q.push(cur->right);
      }
    }
    return ans;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    stringstream ss(data);
    string tmp;
    queue<TreeNode*>q;
    ss>>tmp;
    if(tmp=="#") return nullptr;
    TreeNode* root=new TreeNode(stoi(tmp));
    q.push(root);
    while(!q.empty()){
      TreeNode* cur=q.front();q.pop();
      if (cur==nullptr) continue;
      ss>>tmp;
      if(tmp!="#"){
        TreeNode* l=new TreeNode(stoi(tmp));
        q.push(l);
        cur->left=l;
      }
      ss>>tmp;
      if(tmp!="#"){
        TreeNode* r=new TreeNode(stoi(tmp));
        q.push(r);
        cur->right=r;
      }
    }
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
