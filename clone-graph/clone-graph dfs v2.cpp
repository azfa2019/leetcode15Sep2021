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
    unordered_map<Node*,Node*>mp;
    public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        if(mp.find(node)==mp.end()){
            mp[node]=new Node(node->val);
            for(auto nei:node->neighbors){
                mp[node]->neighbors.push_back(cloneGraph(nei));
            }
        }
        return mp[node];
    }
};
// original.   mp
//  4          2,4
// 1 2            1
