/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(p->right!=nullptr) return findMin(p->right);
        TreeNode* succ=nullptr;
        while(root!=nullptr) {
            if(root->val>p->val){
                succ=root;
                root=root->left;
            }else if(root->val<p->val){
                root=root->right;
            }else break;
        }
        return succ;
    }
    TreeNode* findMin(TreeNode* node){
        while(node->left!=nullptr) node=node->left;
        return node;
    }
};
//                6
//           2          8
//       0      4     7    9
//.           3   5