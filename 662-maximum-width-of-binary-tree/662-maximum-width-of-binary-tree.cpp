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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        int width=0;
        while(q.size()){
            int cnt=q.size();
            int start=q.front().second;
            int idx;
            while(cnt--){
                auto cur=q.front().first;
                idx=q.front().second;
                q.pop();
                if(cur->left) q.push({cur->left,(long long) idx*2-start*2});
                if(cur->right) q.push({cur->right,(long long) idx*2+1-start*2});
            }
            width=max(width,idx-start+1);
        }
        return width;
    }
};