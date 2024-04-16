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
    int val,depth;
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1){
            auto cur=new TreeNode(v);
            cur->left=root;
            return cur;
        }
        queue<TreeNode*>q;
        q.push(root);
        for(int i=0;i<d-2;i++){
            for(int j=q.size();j;j--){
                auto t=q.front();q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }
        while(q.size()){
            auto t=q.front();q.pop();
            auto left=new TreeNode(v),right=new TreeNode(v);
            left->left=t->left,right->right=t->right;
            t->left=left,t->right=right;
        }
        return root;
    }
};