class Solution {
    class UF{
        public:
        vector<int>parent;
        vector<int>rank;
        UF(int n){
            parent=vector<int>(n,0);
            rank=vector<int>(n,0);
            for(int i=0;i<parent.size();i++) parent[i]=i;
        }
        bool unionNodes(int n1,int n2){
            int p1=findroot(n1);
            int p2=findroot(n2);
            if(p1==p2) return false;
            if(rank[p1]<rank[p2]) parent[p1]=p2;
            else if(rank[p1]>rank[p2]) parent[p2]=p1;
            else parent[p2]=p1,rank[p1]++;
            return true;
        }
        int findroot(int n){
            if(n!=parent[n]) parent[n]=findroot(parent[n]);
            return parent[n];
        }
    };
    public:
    bool validTree(int n, vector<vector<int>>& edges) {
        UF uf=UF(n);
        for(auto e:edges){
            if(uf.unionNodes(e[0],e[1])==false) return false;
        }
        int root=uf.findroot(0);
        for(int i=0;i<n;i++){
            if(root!=uf.findroot(i)) return false;
        }
        return true;
    }
};