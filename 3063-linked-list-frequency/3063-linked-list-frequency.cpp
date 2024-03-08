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
    ListNode* frequenciesOfElements(ListNode* head) {
        unordered_map<int,int>hash;
        auto node=head;
        while(node){
            hash[node->val]++;
            node=node->next;
        }
        auto dummy=new ListNode(0);
        auto dummy0=dummy;
        for (auto e:hash){
            auto cur=new ListNode(e.second);
            //cout<<e.second<<endl;
            dummy->next=cur;
            dummy=cur;
        }
        return dummy0->next;
    }
};