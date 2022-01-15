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
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root)[0];
    }
    vector<long long> dfs(TreeNode* node){
        if(!node) return {1,LLONG_MAX,LLONG_MIN};
        auto l=dfs(node->left);
        auto r=dfs(node->right);
        if(l[0] && r[0] && node->val>l[2] && node->val<r[1]){
            int curMin= node->left?l[1]:node->val;
            int curMax=node->right?r[2]:node->val;
            return {1,curMin,curMax};
        }else return {0,0,0};
    }
};