class Solution {
public:
    bool cmp(pair<string,int>& s1,pair<string,int>& s2){
        if(s1.second==s2.second) return s1.first<s2.first;
        return s1.second>s2.second;   
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>hash;
        for(auto& s:words) hash[s]++;
        typedef pair<int,string> PIS;
        vector<PIS> ws;
        for(auto [k,v]:hash) ws.push_back({v,k});
        auto cmp=[](PIS& a,PIS& b){
            if(a.first!=b.first) return a.first<b.first;
            return a.second>b.second;
        };
        make_heap(ws.begin(),ws.end(),cmp);
        vector<string>res;
        while(k--) {
            res.push_back(ws[0].second);
            pop_heap(ws.begin(),ws.end(),cmp);
            ws.pop_back();
        }
        return res;
    }
};