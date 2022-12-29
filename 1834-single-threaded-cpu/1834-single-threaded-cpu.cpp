typedef pair<long,long> PII;
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int i=0;i<tasks.size();i++) tasks[i].push_back(i);
        sort(tasks.begin(),tasks.end());
        priority_queue<PII,vector<PII>,greater<>> heap; //duration,index
        vector<int>res;
        long curTime=0;
        for(auto& t:tasks){
            while(heap.size()&&curTime<t[0]){
                curTime+=heap.top().first;
                res.push_back(heap.top().second);
                heap.pop();
            }
            curTime=max(curTime,(long)t[0]); 
            heap.push({t[1],t[2]});
        }
        while(heap.size()) res.push_back(heap.top().second),heap.pop();
        return res;
    }
};