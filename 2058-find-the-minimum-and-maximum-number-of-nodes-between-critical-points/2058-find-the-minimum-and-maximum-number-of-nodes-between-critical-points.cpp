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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>a,b;
        for(;head;head=head->next){
            a.push_back(head->val);
        }
        if(a.size()<=2) return {-1,-1};
        for(int i=1;i<a.size()-1;i++){
            if((a[i]>a[i-1]&&a[i]>a[i+1])||(a[i]<a[i-1]&&a[i]<a[i+1])) b.push_back(i);
        }
        if(b.size()<=1) return {-1,-1};
        sort(b.begin(),b.end());
//for(auto num:b) cout<<num<<endl;
        int mind=2e5,maxd=-1;
        for(int i=1;i<b.size();i++) mind=min(mind,b[i]-b[i-1]);
        return {mind,b.back()-b[0]};
    }
};