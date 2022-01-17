/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*>mp;
        if(!node) return nullptr;
        queue<Node*>q;
        q.push(node);
        while(q.size()){
            auto cur=q.front();q.pop();
            if(mp.find(cur)==mp.end()) mp[cur]=new Node(cur->val);
            for(auto next:cur->neighbors){
                if(mp.find(next)==mp.end()) {
                    q.push(next);
                    mp[next]=new Node(next->val);
                }
                mp[cur]->neighbors.push_back(mp[next]);
            }
        }
        return mp[node];
    }
};