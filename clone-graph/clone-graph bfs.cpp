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
    if(node==nullptr) return nullptr;
    unordered_map<Node*,Node*>map;
    Node* newnode=new Node(node->val);
    map[node]=newnode;
    queue<Node*>q;
    q.push(node);
    while(!q.empty()){
      Node* cur=q.front();
      q.pop();
      if(map.find(cur)==map.end()) map[cur]=new Node(cur->val);
      for(auto nei:cur->neighbors){
        if(map.find(nei)==map.end()) {
          q.push(nei);
          Node* tmp=new Node(nei->val);
          map[nei]=tmp;
        }
        map[cur]->neighbors.push_back(map[nei]);
      }
    }
    return newnode;
  }
};
