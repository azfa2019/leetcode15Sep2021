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
    vector<int> dfs(TreeNode* node){
        if(!node) return {0,true,INT_MAX,INT_MIN};
        auto l=dfs(node->left);
        auto r=dfs(node->right);
        if(!l[1] || !r[1] || node->val<=l[3] || node->val>=r[2]) 
            return {0,false,0,0};
        int curSum=node->val+l[0]+r[0];
        int curMin=node->left?l[2]:node->val;
        int curMax=node->right?r[3]:node->val;
        ans=max(ans,curSum);
        return {curSum,true,curMin,curMax};
    }
    //public:
    //int maxsum = 0;
    //int maxSumBST(TreeNode* root) {
    //    dfs(root);
    //    return maxsum;
    //}
    //vector<int> dfs(TreeNode* root) {
    //    if (!root) return {true, INT_MAX, INT_MIN, 0};
    //    auto lArr = dfs(root->left);
    //    auto rArr = dfs(root->right);
    //    int sum = 0, curmax, curmin;
    //    if (!lArr[0] || !rArr[0] || root->val >= rArr[1] || root->val <= lArr[2]) {
    //        return {false, 0, 0, 0};
    //    }
    //    curmin = root->left ? lArr[1] : root->val;
    //    curmax = root->right ? rArr[2] : root->val;
    //    sum += (root->val + lArr[3] + rArr[3]);
    //    maxsum = max(maxsum, sum);
    //    return {true, curmin, curmax, sum};
    //}

};