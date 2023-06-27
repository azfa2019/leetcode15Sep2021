typedef vector<int> VI;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        if(a.empty()||b.empty()) return {};
        int n=a.size(),m=b.size();
        priority_queue<VI,vector<VI>,greater<VI>>heap;
        for(int i=0;i<m;i++) heap.push({b[i]+a[0],0,i});
        vector<VI>res;
        while(k-- && heap.size()){
            auto t=heap.top(); heap.pop();
            res.push_back({a[t[1]],b[t[2]]});
            if(t[1]+1<n) heap.push({a[t[1]+1]+b[t[2]],t[1]+1,t[2]});
        }
        return res;
    }
};