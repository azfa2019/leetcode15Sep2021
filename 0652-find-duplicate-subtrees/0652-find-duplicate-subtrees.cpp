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
    vector<TreeNode*> ans;
    unordered_map<string,int>ids;
    unordered_map<int,int>hash;
    int cnt=0;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* root){
        if(!root) return 0;
        int left=dfs(root->left);
        int right=dfs(root->right);
        string key=to_string(left)+to_string(right)+to_string(root->val);
        if(ids.count(key)==0) ids[key]=++cnt;
        int id=ids[key];
        if(++hash[id]==2) ans.push_back(root);
        return id;
    }
};