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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        if(!root) return nullptr;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            int size=q.size();
            vector<TreeNode*>level;
            int idx=-1;
            for(int i=0;i<size;i++){
                auto cur=q.front();q.pop();
                level.push_back(cur);
                if(cur==u) idx=i;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            if(idx!=-1) return idx+1>size-1?nullptr:level[idx+1];
        }
        return nullptr;
    }
};
