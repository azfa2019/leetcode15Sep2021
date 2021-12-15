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
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;
        ListNode* dummyHead=new ListNode();
        dummyHead->next=head;
        ListNode* lastSorted=head;
        ListNode* cur=head->next;
        
        while(cur){
            if(lastSorted->val<=cur->val){
                lastSorted=lastSorted->next;
            }else{
                ListNode* pre=dummyHead;
                while(pre->next->val<=cur->val) pre=pre->next;
                lastSorted->next=cur->next;
                cur->next=pre->next;//lastSorted;
                pre->next=cur;
            }
            cur=lastSorted->next;
        }
        return dummyHead->next;
    }
};

// 1   2    4   3
//     pre last cur 