/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
  public:
  Node* flatten(Node* head) {
    dfs(head);
    return head;
  }
  Node* dfs(Node* h){
    if(h==nullptr) return nullptr;
    Node* child=h->child;
    Node* next=h->next;
    h->child=nullptr;

    if(child!=nullptr && next!=nullptr){
      Node* lastChild=dfs(child);
      Node* lastNext=dfs(next);
      h->next=child;
      child->prev=h;
      lastChild->next=next;
      next->prev=lastChild;
      return lastNext;
    }else if(child==nullptr && next!=nullptr){
      Node* lastNext=dfs(next);
      return lastNext;
    }else if(child!=nullptr && next==nullptr){
      h->next=child;
      child->prev=h;
      Node* lastChild=dfs(child);
      return lastChild;
    }else return h;
  }
};