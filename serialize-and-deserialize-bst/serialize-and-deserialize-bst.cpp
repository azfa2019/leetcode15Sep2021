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
    string str;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
      int count=q.size();
        auto node=q.front();
        q.pop();
        if(node==nullptr) str+="#";
        else{
          str+=to_string(node->val)+"!";
          q.push(node->left);
          q.push(node->right);
        }
      }
    return str;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if(data.size()==0) return nullptr;
    int i=0,j=0;
    if(data[i]=='#') return nullptr;
    while(j<data.size() && data[++j]!='!');
    TreeNode* root=new TreeNode(stoi(data.substr(i,j-i)));
    queue<TreeNode*>q;
    q.push(root);
    while(i<data.size()){
      TreeNode* node=q.front();
      q.pop();
      if(node==nullptr) continue;
      
      i=++j;
      if(i>=data.size()) break;
      if(data[i]=='#'){
        node->left=nullptr;
      }else{
        while(j<data.size() && data[++j]!='!');
        node->left=new TreeNode(stoi(data.substr(i,j-i)));
      }
      q.push(node->left);

      i=++j;
      if(i>=data.size()) break;
      if(data[i]=='#'){
        node->right=nullptr;
      }else{
        while(j<data.size() && data[++j]!='!');
        node->right=new TreeNode(stoi(data.substr(i,j-i)));
      }
      q.push(node->right);
    }
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;