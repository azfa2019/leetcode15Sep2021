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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root) return res;
        map<int,vector<int>>m;
        queue<pair<int,TreeNode*>>q;
        q.push({0,root});
        while(q.size()){
            auto t=q.front();q.pop();
            m[t.first].push_back(t.second->val);
            if(t.second->left) q.push({t.first-1,t.second->left});
            if(t.second->right) q.push({t.first+1,t.second->right});
        }
        for(auto t:m) res.push_back(t.second);
        return res;
    }
};