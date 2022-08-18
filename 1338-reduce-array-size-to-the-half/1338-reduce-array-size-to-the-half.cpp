typedef pair<int,int>PII;
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>hash;
        int n=arr.size();
        for(int i:arr) hash[i]++;
        priority_queue<PII>pq;
        for(auto p:hash) pq.push({p.second,p.first});
        int cnt=0,res=0;
        while(pq.size()){
            auto t=pq.top();pq.pop();
            cnt+=t.first;
            res++;
            //cout<<cnt<<endl;
            if(cnt>=n/2) return res;
        }
        return 0;
    }
};