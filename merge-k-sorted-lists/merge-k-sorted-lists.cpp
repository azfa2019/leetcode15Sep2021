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
class Solution {
  public:
  struct compare{
    bool operator()(ListNode* a,ListNode* b){
      return a->val>b->val;
    }
  };
  
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    //maintain a minHeap, when popping out the top link next node, and push node->next to minHeap
    //if not nullptr push to minHeap
    priority_queue<ListNode*,vector<ListNode*>,compare>minHeap;
    for(auto l:lists) if(l!=nullptr) minHeap.push(l);
    ListNode* pre=new ListNode(-1);
    auto dummy=pre;
    while(!minHeap.empty()){
      auto cur=minHeap.top();
      minHeap.pop();
      pre->next=cur;
      pre=pre->next;
      if(cur->next!=nullptr){
        minHeap.push(cur->next);
      }
    }
    return dummy->next;
  }
};
//class Solution {
//public:
//    struct compare{
//        bool operator()(const ListNode*a,const ListNode*b){
//            return a->val>b->val;
//        }
//    };
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        //maintain a minHeap, when popping out the top link next node, and push node->next to minHeap
//        priority_queue<ListNode*,vector<ListNode*>,compare> minHeap;
//        for(ListNode* root:lists) 
//            if(root!=nullptr) minHeap.push(root);
//        
//        ListNode*resHead=nullptr, *resTail=nullptr;
//        while(!minHeap.empty()){
//            ListNode* node=minHeap.top();
//            minHeap.pop();
//            if(resHead==nullptr) resHead=resTail=node;
//            else{
//                resTail->next=node;
//                resTail=resTail->next;
//            }
//            if(node->next!=nullptr) minHeap.push(node->next);
//        }
//        return resHead;
//    }
//};