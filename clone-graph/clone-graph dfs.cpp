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
  unordered_map<Node*,Node*>map0;
  public:
  Node* cloneGraph(Node* node) {
    return helper(node);
  }
  Node* helper(Node* node){
    if(node==nullptr) return nullptr;
    if(map0.find(node)==map0.end()) {
      map0[node]=new Node(node->val);
      for(auto nei:node->neighbors){
        map0[node]->neighbors.push_back(helper(nei));
      }
    }
    return map0[node];
  }
};
