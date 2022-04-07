class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int x:stones){
            pq.push(x);
        }

        while(pq.size()>=2){
            int cur=pq.top(); pq.pop();
            int next=pq.top(); pq.pop();
            int collide=abs(cur-next);
            pq.push(collide);
        }
        return pq.top();
    }
};