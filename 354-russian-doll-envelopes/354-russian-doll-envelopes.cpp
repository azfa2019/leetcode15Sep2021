class Solution {
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]) return a[1]>b[1];
        else return a[0]<b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& es) {
        sort(es.begin(),es.end(),cmp);
        vector<int>q;
        for(auto e:es){
            if(q.empty()||e[1]>q.back()) q.push_back(e[1]);
            else {
                auto iter=lower_bound(q.begin(),q.end(),e[1]);
                *iter=e[1];
            }
        }
        return q.size();
    }
};