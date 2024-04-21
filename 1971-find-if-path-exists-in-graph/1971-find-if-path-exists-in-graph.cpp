class Solution {
public:
    vector<int>p;
    int find(int x){
        if(p[x]!=x) p[x]=find(p[x]);
        return p[x];
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        for(auto& e:edges){
            int x=e[0],y=e[1];
            int px=find(x),py=find(y);
            if(px!=py) p[px]=py;
        }
        return find(source)==find(destination);
            
    }
};