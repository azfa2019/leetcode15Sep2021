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
    unordered_map<int,int>hash;
    vector<int> in;
    vector<int> po;
    TreeNode* buildTree(vector<int>& _in, vector<int>& _po) {
        in=_in,po=_po;
        int n=in.size();
        cout<<n<<endl;
        for(int i=0;i<n;i++) hash[in[i]]=i;
        return helper(0,n-1,0,n-1);
    }
    TreeNode* helper(int il,int ir,int pl,int pr){
        if(pl>pr) return NULL;
        TreeNode* root=new TreeNode(po[pr]);
        int k=hash[po[pr]]-il;
        root->left=helper(il,il+k-1,pl,pl+k-1);
        root->right=helper(il+k+1,ir,pl+k,pr-1);
        return root;
    }
};