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
        return to_string(root->val)+" "+serialize(root->left)+" "+serialize(root->right);
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
        TreeNode* node=new TreeNode(stoi(tmp));
        node->left=helper(ss);
        node->right=helper(ss);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
