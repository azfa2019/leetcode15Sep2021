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
    int longestConsecutive(TreeNode* root) {
        dfs(root);
        return ans;
    }
    pair<int,int> dfs(TreeNode* root){
        if(!root) return {0,0};
        //if(root->val==2){
        //    cout<<parent->val<<" ";
        //    cout<<lenInc<<" "<<lenDec<<endl;
        //}
        int inc=1,dec=1;
        if(root->left){
            auto l=dfs(root->left);
            if(root->val==root->left->val+1) dec=l.second+1;
            else if(root->val==root->left->val-1) inc=l.first+1;
        }
        if(root->right){
            auto r=dfs(root->right);
            if(root->val==root->right->val+1) dec=max(dec,r.second+1); 
            else if(root->val==root->right->val-1) inc=max(inc,r.first+1);
        }
        ans=max(ans,inc+dec-1);
        return {inc,dec};
    }
};
//   3
// 4   3
//4  2
