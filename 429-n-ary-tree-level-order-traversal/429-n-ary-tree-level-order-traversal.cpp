/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>res;
        if(!root) return res;
        queue<Node*>q;
        q.push(root);
        while(q.size()){
            vector<int>cur;
            int len=q.size();
            while(len--){
                auto t=q.front();q.pop();
                cur.push_back(t->val);
                for(auto c:t->children) q.push(c);
            }
            res.push_back(cur);
        }
        return res;
    }
};