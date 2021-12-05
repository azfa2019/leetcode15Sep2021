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
    unordered_map<TreeNode*,int>map;
public:
    int rob(TreeNode* root) {
        if(root==nullptr) return 0;
        if(map.find(root)!=map.end()) return map[root];
        int opt1=rob(root->left)+rob(root->right);
        int opt2=root->val+(root->left==nullptr?0:(rob(root->left->left)+rob(root->left->right)))+(root->right==nullptr?0:(rob(root->right->left)+rob(root->right->right)));
        map[root]=max(opt1,opt2);
        return map[root];
    }
};
//    4
//   1 null
// 2 null 
//3
