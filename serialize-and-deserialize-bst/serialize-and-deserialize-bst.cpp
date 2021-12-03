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
            int size=q.size();
            while(size--){
                TreeNode* cur=q.front();q.pop();
                if(cur==nullptr) ans+="#";
                else {
                    ans+=to_string(cur->val)+"!";
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="#") return nullptr;
        int i=0,j=0;
        j=data.find_first_of("!",i);
        TreeNode* root=new TreeNode(stoi(data.substr(i,j-i)));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur=q.front();q.pop();
            if(cur==nullptr) continue;
            i=++j;
            if(i>=data.size()) break;
            if(data[i]=='#') cur->left=nullptr;
            else{
                j=data.find_first_of("!",i);
                cur->left=new TreeNode(stoi(data.substr(i,j-i)));
            }
            q.push(cur->left);

            i=++j;
            if(i>=data.size()) break;
            if(data[i]=='#') cur->right=nullptr;
            else{
                j=data.find_first_of("!",i);
                cur->right=new TreeNode(stoi(data.substr(i,j-i)));
            }
            q.push(cur->right);
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