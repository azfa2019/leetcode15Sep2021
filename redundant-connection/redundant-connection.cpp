class Solution {
    class UF{
        public:
        vector<int>rank,parent;
        UF(int n){
            rank=vector<int>(n,0);
            parent=vector<int>(n,0);
            for(int i=0;i<n;i++) parent[i]=i;
        }
        int findParent(int x){
            if(x!=parent[x]) parent[x]=findParent(parent[x]);
            return parent[x];
        }
        bool unionNodes(int x,int y){
            int px=findParent(x);
            int py=findParent(y);
            if(px==py) return false;
            if(rank[px]>rank[py]) parent[py]=px;
            else if(rank[px]<rank[py]) parent[px]=py;
            else {
                parent[px]=py;
                rank[py]++;
            }
            return true;
        }
    };
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        UF uf=UF(n+1);
        for(auto e:edges){
            if(uf.unionNodes(e[0],e[1])==false) return e;
        }
        return {};
    }
};