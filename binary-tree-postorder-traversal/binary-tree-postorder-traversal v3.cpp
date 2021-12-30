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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>stck;
        vector<int>ans;
        while(root!=nullptr || !stck.empty()){
            if(root!=nullptr){
                ans.push_back(root->val);
                stck.push(root);
                root=root->right;
            }else{
                root=stck.top();stck.pop();
                root=root->left;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
