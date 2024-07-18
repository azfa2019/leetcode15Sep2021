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
    int res=0;
    int countPairs(TreeNode* root, int d) {
        dfs(root,d);
        return res;
    }
    vector<int>dfs(TreeNode* root,int d){
        if(!root) return {};
        if(!root->left && !root->right) return {0};
        vector<int>ret;
        auto left=dfs(root->left,d);
        for(auto&e:left){
            if(++e>d) continue;
            ret.push_back(e);
        }
        auto right=dfs(root->right,d);
        for(auto&e:right){
            if(++e>d) continue;
            ret.push_back(e);
        }
        for(auto l:left)
            for(auto r:right)
                res+=(l+r<=d);
        return ret;
    }
};