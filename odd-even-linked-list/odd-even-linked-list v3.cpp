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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddHead=new ListNode();
        //oddHead->next=head;
        ListNode* oddTail=oddHead;
        ListNode* evenHead=new ListNode();
        ListNode* evenTail=evenHead;
        bool isOdd=true;
        while(head!=nullptr){
            if(isOdd){
                oddTail->next=head;
                oddTail=oddTail->next;
            }else{
                evenTail->next=head;
                evenTail=evenTail->next;
            }
            head=head->next;
            isOdd=!isOdd;
        }
        oddTail->next=evenHead->next;
        evenTail->next=nullptr;
        return oddHead->next;
    }
};
