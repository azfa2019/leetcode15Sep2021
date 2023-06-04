class Solution {
public:
    vector<int>p;
    int findCircleNum(vector<vector<int>>& g) {
        int n=g.size();
        for(int i=0;i<n;i++) p.push_back(i);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(i!=j && g[i][j]){
                    int pi=find(i),pj=find(j);
                    if(pi!=pj) p[pi]=pj;
                }
        unordered_set<int>S;
        for(int i=0;i<n;i++) {
            int pi=find(i);
            S.insert(pi);
        }
        return S.size();
    }
    int find(int x){
        if(x!=p[x]) p[x]=find(p[x]);
        return p[x];
    }
};