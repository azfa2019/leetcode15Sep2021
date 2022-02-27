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
            int size=q.size();
            int start=q.front().second;
            int index;
            while(size--){
                auto cur=q.front();q.pop();
                index=cur.second;
                if(cur.first->left) q.push({cur.first->left,(long long) index*2-start*2});
                if(cur.first->right) q.push({cur.first->right,(long long) index*2+1-start*2});
            }
            width=max(width,index-start+1);
        }
        return width;
    }
};