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
        if(head==nullptr) return nullptr;
        ListNode* odd=head, *even=head->next;
        if(even==nullptr) return head;
        ListNode* even0=even;
        while(odd!=nullptr && even!=nullptr){
            ListNode* oddTmp=even->next;
            ListNode* evenTmp=nullptr;
            if(oddTmp!=nullptr) evenTmp=oddTmp->next;
            odd->next=oddTmp;
            even->next=evenTmp;
            if(odd->next!=nullptr) odd=odd->next;
            even=even->next;
        }
        
        odd->next=even0;
        return head;
        //1 2 3 4 null
        //o e.o e o  e
        
    }
};
