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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>res(m,vector<int>(n,-1));
        int dirx[4]={0,1,0,-1},diry[]={1,0,-1,0};
        int x=0,y=0,di=0,dx,dy;
        while(head){
            res[x][y]=head->val;
            head=head->next;
            dx=dirx[di],dy=diry[di];
            if(x+dx<0||x+dx>=m||y+dy<0||y+dy>=n||res[x+dx][y+dy]!=-1){
                di=(di+1)%4;
                dx=dirx[di],dy=diry[di];
            }
            x+=dx,y+=dy;
        }
        return res;
    }
};