/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<TreeNode*>nodes;
    vector<int>vals;
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        find(root,head->val);
        while(head) {
            vals.push_back(head->val);
            head=head->next;
        }
        for(auto node:nodes){
            if(dfs(0,node)) return true;
        }
        return false;
    }
    bool dfs(int idx,TreeNode* node){
        if(idx==vals.size()) return true;
        if(!node) return false;
        if(node->val!=vals[idx]) return false;
        return dfs(idx+1,node->left) || dfs(idx+1,node->right);
    }
    void find(TreeNode* node,int val){
        if(!node) return;
        if(node->val==val) nodes.push_back(node);
        find(node->left,val);
        find(node->right,val);
    }
};