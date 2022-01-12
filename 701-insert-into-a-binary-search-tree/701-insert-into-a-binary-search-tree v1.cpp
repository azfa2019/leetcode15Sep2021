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
    TreeNode* nearNode;
    int minDiff=INT_MAX;
    public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        auto node=preorder(root,val);
        if(!node) {
            node=new TreeNode(val);
            if(root->left==nullptr) root->left=node;
            else{
                auto cur=root->left;
                while(cur->left) cur=cur->left; 
                cur->left=node;
            }
            return root;
        }
        if(node->right==nullptr) node->right=new TreeNode(val);
        else {
            auto cur=node->right;
            while(cur->left) cur=cur->left;
            cur->left=new TreeNode(val);
        }
        return root;
    }
    TreeNode* preorder(TreeNode* node,int val){
        if(!node) return nullptr;
        preorder(node->left,val);
        if(val>node->val) {
            if(val-node->val<minDiff){
                nearNode=node;
                minDiff=val-node->val;
            }
        }
        preorder(node->right,val);
        return nearNode;
    }
};
