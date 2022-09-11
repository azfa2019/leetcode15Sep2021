const int mod=1e9+7;
class Solution {
public:
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        vector<vector<int>>es;
        for(int i=0;i<e.size();i++)
            es.push_back({e[i],s[i]});
        sort(es.rbegin(),es.rend());
        long long ans=0,sum=0;
        priority_queue<int,vector<int>,greater<int>>q;
        for(int i=0;i<es.size();i++){
            if(i>=k){
                sum-=q.top();
                q.pop();
            }
            sum+=es[i][1];
            q.push(es[i][1]);
            ans=max(ans,sum*es[i][0]);
        }
        return ans%mod;
    }
};