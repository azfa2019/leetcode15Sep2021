class Solution {
public:
    typedef pair<int,int> PII;
    int reductionOperations(vector<int>& nums) {
        unordered_map<int,int>all;
        
        for(int n:nums) all[n]++;
        priority_queue<PII>heap;
        for(auto& p:all) heap.push(p);
        int cnt=0;
        while(heap.size()>1){
            auto t1=heap.top();heap.pop();
            auto t2=heap.top();heap.pop();
            t2.second+=t1.second;
            cnt+=t1.second;
            heap.push(t2);
        }
        return cnt;
    }
};