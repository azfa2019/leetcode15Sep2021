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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>stck;
        auto cur=root;
        while(cur!=nullptr || !stck.empty()){
            if(cur!=nullptr){
                ans.push_back(cur->val);
                stck.push(cur);
                cur=cur->left;
            }else{
                cur=stck.top();stck.pop();
                cur=cur->right;
            }
        }
        return ans;
    }
};
//     1
//   2   5
// 3  4
// cur=   1
// ans:   1
// stack: 1 
//
// cur=   2
// ans:   1 2
// stack: 1 2
//
// cur=   3
// ans:   1 2 3
// stack: 1 2 3
//
// cur=   n
// ans:   1 2 3
// stack: 1 2 
//
// cur=   4
// ans:   1 2 3
// stack: 1  
//
// cur=   n
// ans:   1 2 3 4
// stack: 1 4 
//
// cur=   5
// ans:   1 2 3 4
// stack:   
//
// cur=   n
// ans:   1 2 3 4 5
// stack:  
//