class Solution {
public:
    vector<int>p;
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        for(int i=0;i<n;i++) p.push_back(i);
        int res=n;
        for(auto e:connections){
            int a=e[0],b=e[1];
            if(find(a)!=find(b)) p[find(a)]=find(b),res--;
        }
        return res-1;
    }
    int find(int x){
        if(p[x]!=x) p[x]=find(p[x]);
        return p[x];
    }
};