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
    Node* cloneTree(Node* root) {
        if(!root) return nullptr;
        unordered_map<Node*,Node*>mp;
        mp[root]=new Node(root->val);
        queue<Node*>q;
        q.push(root);
        while(q.size()){
            auto cur=q.front();q.pop();
            for(auto next:cur->children){
                if(!mp.count(next)){
                    mp[next]=new Node(next->val);
                    q.push(next);
                }
                mp[cur]->children.push_back(mp[next]);
            }
        }
        return mp[root];
    }
};