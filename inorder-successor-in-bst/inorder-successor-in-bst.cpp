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
        TreeNode* ans=nullptr;
        TreeNode* tmp=root;
        while(root!=nullptr){
            if(root->val<=p->val){
                root=root->right;
            } else {
                ans=root;
                root=root->left;
            }
        }
        return ans;
    }
};
//                6
//           2          8
//       0      4     7    9
//.           3   5