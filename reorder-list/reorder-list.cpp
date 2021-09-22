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
  void reorderList(ListNode* head) {
    ListNode* fast=new ListNode();
    ListNode* slow=new ListNode();
    //fast->next=head;
    //slow->next=head;
    fast=head;
    slow=head;
    //1(fast,slow)>2>3>4
    while(fast!=nullptr && fast->next!=nullptr) {
      fast=fast->next->next; //fast=3, slow=2; fast=nullptr, slow=3
      slow=slow->next;
    //1>2>3(slow)>4>null(fast)
    }
    //cout<<slow->val<<endl;
    ListNode* left=head,*right=reverse(slow);
    //while(left!=nullptr) cout<<left->val<<endl,left=left->next;
    //cout<<"---"<<endl;
    //while(right!=nullptr) cout<<right->val<<endl,right=right->next;
    //cout<<left->val<<endl;
    //cout<<right->val<<endl;
    while(right!=nullptr && left!=nullptr){
      ListNode* tmp=left->next;
      left->next=right;
      left=tmp;
      tmp=right->next;
      right->next=left;
      right=tmp;
    }
    if(left!=nullptr) left->next=nullptr;
    //cout<<left->val<<endl;
    //cout<<right<<endl;
    //while(head!=nullptr) cout<<head->val<<endl,head=head->next;

  }
  ListNode* reverse(ListNode* head){
    ListNode*  pre=nullptr;
    while(head!=nullptr){
      ListNode* tmp=head->next;
      head->next=pre;
      pre=head;
      head=tmp;
    }
    return pre;
  }
};

//1(left)>2>3>null
//5(right)>4>3>null
    //while(right!=nullptr && left!=nullptr){
    //  ListNode* tmp=left->next; 
//1>5>2>4>3(right,left)>null(tmp)
    //  left->next=right; 
//1>5>2>4>3(right,left) null(tmp)
    //  left=tmp; 
//1>5>2>4>3(right) null(left)
    //  tmp=right->next; 
//1>5>2>4>3(right,tmp) null(left)
    //  right->next=left;
//1>5>2>4>3(right,tmp)>null(left)
    //  right=tmp;
//1>5>2>4>3(right,tmp)>null(left)
    //}