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
typedef long long LL;
int M=1e9+7;
class Solution {
    int idx=0;
    vector<int>sums;
public:
    int maxProduct(TreeNode* root) {
        LL sum=getSum(root);
        LL ans=0;
        for(int n:sums){
            LL tmp=n*(sum-n);
            ans=max(ans,tmp);
        }
        return ans%M;
    }
    int getSum(TreeNode* node){
        if(!node) return 0;
        int l=getSum(node->left);
        int r=getSum(node->right);
        sums.push_back(l);
        sums.push_back(r);
        return l+r+node->val;
    }
};
