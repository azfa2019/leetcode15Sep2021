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
    map<int,vector<vector<int>> >hash;
    void dfs(TreeNode* root,int x,int y){
        if(!root) return;
        hash[y].push_back({x,root->val});
        dfs(root->left,x+1,y-1);
        dfs(root->right,x+1,y+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root,0,0);
        vector<vector<int>>res;
        for(auto& [k,v]:hash){
            sort(v.begin(),v.end());
            vector<int>col;
            for(auto& p:v) col.push_back(p[1]);
            res.push_back(col);
        }
        return res;
    }
};