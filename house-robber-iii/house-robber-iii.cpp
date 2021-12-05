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
        int tmp1=root->left==nullptr?0:rob(root->left->left)+rob(root->left->right);
        int tmp2=root->right==nullptr?0:rob(root->right->left)+rob(root->right->right);
        int opt1=root->val+tmp1+tmp2;
        int opt2=rob(root->left)+rob(root->right);
        map[root]=max(opt1,opt2);
        return map[root];
    }
};