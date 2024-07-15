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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        
        unordered_map<int,TreeNode*>hashNode;
        unordered_map<int,int>in;
        for(auto& v:d){
            if(!hashNode.count(v[0])) {
                TreeNode* p=new TreeNode(v[0]);
                hashNode[v[0]]=p;
            }
            if(!hashNode.count(v[1])) {
                TreeNode* c=new TreeNode(v[1]);
                hashNode[v[1]]=c;
            }
            if(v[2]==1) hashNode[v[0]]->left=hashNode[v[1]];
            else hashNode[v[0]]->right=hashNode[v[1]];
            in[v[0]]+=0;
            in[v[1]]++;
        }
        //for(auto& [e,v]: in) cout<<e<<"; "<<v<<endl;
        for(auto& [e,v]: in) if(v==0) return hashNode[e];
        return nullptr;
    }
};