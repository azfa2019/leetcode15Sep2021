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
    bool check(TreeNode* root,int x,string& s){
        if(root->val==x) return true;
        if(root->left){
            s.push_back('L');
            if(check(root->left,x,s)) return true;
            s.pop_back();
        }
        if(root->right){
            s.push_back('R');
            if(check(root->right,x,s)) return true;
            s.pop_back();
        }
        return false;
    }
    string getDirections(TreeNode* root, int s, int d) {
        string s1,s2;
        check(root,s,s1);
        check(root,d,s2);
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        while(s1.size()&&s2.size()&&s1.back()==s2.back())
            s1.pop_back(),s2.pop_back();
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        string ans=string(s1.size(),'U')+s2;
        return ans;
    }
};