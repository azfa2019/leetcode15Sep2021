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
        queue<TreeNode*>q;
        q.push(root);
        string ans;
        while(!q.empty()){
            TreeNode* node=q.front();q.pop();
            if(node==nullptr) ans+="#";
            else{
                ans+=to_string(node->val)+"!";
                q.push(node->left);
                q.push(node->right);
            }
        }
        //cout<<ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="#") return nullptr;
        int i=0,j=0;
        j=data.find("!",i);
        TreeNode* root=new TreeNode(stoi(data.substr(i,j-i)));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();q.pop();
            if(node==nullptr) continue;
            i=++j;
            if(i>=data.size()) break;
            if(data[i]=='#') node->left=nullptr;
            else{
                j=data.find("!",i);
                node->left=new TreeNode(stoi(data.substr(i,j-i)));
            }
            q.push(node->left);
            
            i=++j;
            if(i>=data.size()) break;
            if(data[i]=='#') node->right=nullptr;
            else {
                j=data.find("!",i);
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