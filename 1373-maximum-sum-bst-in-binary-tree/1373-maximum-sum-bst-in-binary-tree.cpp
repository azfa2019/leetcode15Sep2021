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
    int ans=0;
public:
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
    vector<int>dfs(TreeNode* node){
        if(!node) return {0,true,INT_MAX,INT_MIN};
        auto l=dfs(node->left);
        auto r=dfs(node->right);
        if(l[1] && r[1] && node->val > l[3] && node->val<r[2]){
            int sum=node->val+l[0]+r[0];
            int curMin=node->left?l[2]:node->val;
            int curMax=node->right?r[3]:node->val;
            ans=max(ans,sum);
            return {sum,true,curMin,curMax};
        }else return {0,false,0,0};
    }
};