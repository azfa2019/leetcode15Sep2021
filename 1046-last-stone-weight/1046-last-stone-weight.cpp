class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>,less<>>heap;
        for(int x:stones) heap.push(x);
        while(heap.size()>=2){
            if(!heap.top()) break;
            int a=heap.top();heap.pop();
            int b=heap.top();heap.pop();
            if(a!=b) heap.push(abs(a-b));
            else heap.push(0);
        }
        return heap.top();
    }
};