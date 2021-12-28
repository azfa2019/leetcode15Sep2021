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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* pre=new ListNode();
        ListNode* dummyPre=pre;
        ListNode* tmp=new ListNode();
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val<list2->val) {
                tmp=list1->next;
                pre->next=list1;
                list1=tmp;
                pre=pre->next;
            }else{
                tmp=list2->next;
                pre->next=list2;
                list2=tmp;
                pre=pre->next;
            }
        }
        pre->next=(list1==nullptr?list2:list1);
        return dummyPre->next;
    }
};
//         p l1
//pre> 1 2 4 n
//     |/|/
//     1 3 4 n
//         l2