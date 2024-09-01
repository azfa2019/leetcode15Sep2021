/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode* cur=new PolyNode(),*p= poly1, *q=poly2;
        PolyNode* dummy=cur;
        while(p && q){
            if(p->power>q->power) {
                cur->next=new PolyNode(p->coefficient,p->power);
                cur=cur->next;
                p=p->next;
            }else if(p->power<q->power) {
                cur->next=new PolyNode(q->coefficient,q->power);
                cur=cur->next;
                q=q->next;
            }else {
                int s=p->coefficient+q->coefficient;
                if(s){
                    cur->next=new PolyNode(s,q->power);
                    cur=cur->next;
                }
                p=p->next,q=q->next;
            }
        }
        while(p){
            cur->next=new PolyNode(p->coefficient,p->power);
            cur=cur->next;
            p=p->next;
        }
        while(q){
            cur->next=new PolyNode(q->coefficient,q->power);
            cur=cur->next;
            q=q->next;
        }
        return dummy->next;
        
    }
};