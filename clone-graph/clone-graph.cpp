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
    unordered_map<Node*,Node*>map;
    return helper(node,map);
  }
  Node* helper(Node* node,unordered_map<Node*,Node*>&map){
    if(node==nullptr) return nullptr;
    if(map.find(node)==map.end()) {
      map[node]=new Node(node->val);
      for(auto nei:node->neighbors){
        map[node]->neighbors.push_back(helper(nei,map));
      }
    }
    return map[node];
  }
};