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
    TreeNode* correctBinaryTree(TreeNode* root) {
        unordered_map<TreeNode*,TreeNode*>hash;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            for(int i=q.size()-1;i>=0;i--){
                TreeNode* cur=q.front(); q.pop();
                if(hash.count(cur->left)||hash.count(cur->right)) {
                    TreeNode* p=hash[cur];
                    if(cur==p->left) p->left=NULL;
                    else p->right=NULL;
                    return root;
                }
                if(cur->left) q.push(cur->left),hash[cur->left]=cur;
                if(cur->right) q.push(cur->right),hash[cur->right]=cur;
            }
        }
        return root;
    }
};