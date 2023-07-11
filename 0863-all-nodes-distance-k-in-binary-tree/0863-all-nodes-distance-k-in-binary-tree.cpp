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
    unordered_map<TreeNode*,vector<TreeNode*>>g;
    vector<int>ans;
    void dfs1(TreeNode* root){
        if(root->left) {
            g[root].push_back(root->left);
            g[root->left].push_back(root);
            dfs1(root->left);
        }
        if(root->right) {
            g[root].push_back(root->right);
            g[root->right].push_back(root);
            dfs1(root->right);
        }
    }
    void dfs2(TreeNode* root,TreeNode* father,int k){
        if(!k) ans.push_back(root->val);
        else{
            for(auto& son:g[root]){
                if(son!=father) dfs2(son,root,k-1);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs1(root);
        dfs2(target,NULL,k);
        return ans;
    }
};