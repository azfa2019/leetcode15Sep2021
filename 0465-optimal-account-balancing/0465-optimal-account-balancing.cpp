class Solution {
public:
    int minTransfers(vector<vector<int>>& tr) {
        unordered_map<int,int>hash;
        for(auto& t:tr){
            hash[t[0]]-=t[2];
            hash[t[1]]+=t[2];
        }
        vector<int>a;
        for(auto& p:hash)
            if(p.second) a.push_back(p.second);
        return dfs(a,0);
    }
    int dfs(vector<int>&a,int st){
        int n=a.size();
        while(st<n && a[st]==0) st++;
        if(st==n) return 0;
        int res=INT_MAX;
        for(int i=st+1;i<n;i++)
            if(a[i]*a[st]<0){
                a[i]+=a[st];
                res=min(res,1+dfs(a,st+1));
                a[i]-=a[st];
            }
        return res;
    }
};