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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        for(auto p=head;p;p=p->next) n++;
        vector<ListNode*>res;
        auto p=head;
        for(int i=0;i<k;i++){
            int len=n/k;
            if(i+1<=n%k) len++;
            res.push_back(p);
            for(int j=0;j<len-1;j++) p=p->next;
            if(p){
                auto q=p->next;
                p->next=nullptr;
                p=q;
            }
        }
        return res;
    }
};