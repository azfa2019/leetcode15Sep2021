class Solution {
public:
    vector<int>p;
    int find(int x){
        if(p[x]!=x) p[x]=find(p[x]);
        return p[x];
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>cnt(n,1);
        p.resize(n);
        for(int i=0;i<n;i++) p[i]=i;
        for(auto& e:edges){
            int a=e[0],b=e[1];
            int pa=find(a),pb=find(b);
            if(pa!=pb) {
                p[pa]=pb;
                cnt[pb]+=cnt[pa];
            }
        }
        long long res=0;
        for(int i=0;i<n;i++){
            int pi=find(i);
            if(pi==i)
                res+=(long long)cnt[pi]*(n-cnt[pi]);
        }
        return res/2;
    }
};