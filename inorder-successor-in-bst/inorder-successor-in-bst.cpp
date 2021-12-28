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
    TreeNode* ans=nullptr;
    TreeNode* last=nullptr;
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        dfs(root,p);
        return ans;
    }
    bool dfs(TreeNode* node,TreeNode* p){
        if(node==nullptr) return false;
        if(dfs(node->left,p)) return true;
        if(last==p) {
            ans=node;
            return true;
        }else
            last=node;
        if(dfs(node->right,p)) return true;
        return false;
    }
};
//                6
//           2          8
//       0      4     7    9
//.           3   5