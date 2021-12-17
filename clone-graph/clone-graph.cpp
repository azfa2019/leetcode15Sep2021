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
        queue<Node*>q;
        if(!node) return nullptr;
        q.push(node);
        unordered_map<Node*,Node*>mp;
        while(!q.empty()){
            int levelSize=q.size();
            while(levelSize--){
                auto cur=q.front();
                q.pop();
                if(mp.find(cur)==mp.end()) mp[cur]=new Node(cur->val);
                for(auto nei:cur->neighbors){
                    if(mp.find(nei)==mp.end()) {
                        q.push(nei);
                        mp[nei]=new Node(nei->val);
                    }
                    mp[cur]->neighbors.push_back(mp[nei]);
                }
            }
        }
        return mp[node];
    }
};
// original.   mp
//  4          2,4
// 1 2            1