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
    const int INF=1e8;
    vector<int> dfs(TreeNode* root){
        if(!root) return {0,0,INF};
        auto l=dfs(root->left),r=dfs(root->right);
        return {
            min(l[1],l[2])+min(r[1],r[2]),
            min(l[2]+min(r[1],r[2]),r[2]+min(l[1],l[2])),
            1+min(l[0],min(l[1],l[2]))+min(r[0],min(r[1],r[2]))
        };
            
    }
    int minCameraCover(TreeNode* root) {
        auto f=dfs(root);
        return min(f[1],f[2]);
    }
};