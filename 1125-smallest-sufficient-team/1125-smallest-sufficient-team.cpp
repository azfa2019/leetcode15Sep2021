class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& sk, vector<vector<string>>& peo) {
        int n=sk.size(),m=peo.size();
        vector<int>f(1<<n,n+1),g(m);
        vector<pair<int,int>>path(1<<n);
        unordered_map<string,int>hash;
        int id=0;
        for(int i=0;i<n;i++) hash[sk[i]]=i;
        for(int i=0;i<m;i++){
            for(auto& s:peo[i])
                g[i]|=1<<hash[s];
        }
        f[0]=0;
        for(int i=0;i<1<<n;i++)
            for(int j=0;j<m;j++){
                int& v=f[i|g[j]];
                if(v>f[i]+1){
                    path[i|g[j]]={i,j};
                    v=f[i]+1;
                }
                    
            }
        vector<int>res;
        for(int st=(1<<n)-1;st;){
            res.push_back({path[st].second});
            st=path[st].first;
        }
        return res;
    }
};