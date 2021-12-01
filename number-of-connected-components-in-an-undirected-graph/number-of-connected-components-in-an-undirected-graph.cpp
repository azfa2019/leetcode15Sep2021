class UF{
    public:
    vector<int>parent;
    vector<int>rank;
    UF(int n){
        parent=vector<int>(n,0);
        rank=vector<int>(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int findParent(int i){
        if(i!=parent[i]) parent[i]=findParent(parent[i]);
        return parent[i];
    }
    bool unionNodes(int x,int y){
        int px=findParent(x);
        int py=findParent(y);
        if(px==py) return false;
        if(rank[px]<rank[py]) parent[px]=py;
        else if(rank[px]>rank[py]) parent[py]=px;
        else parent[px]=py,rank[py]++;
        return true;
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UF uf=UF(n);
        for(auto e:edges){
            uf.unionNodes(e[0],e[1]);
        }
        unordered_set<int>set;
        for(int i=0;i<n;i++)
            set.insert(uf.findParent(i));
        return set.size();
    }
};