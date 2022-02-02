class Solution {
    class UF{
        public:
        vector<int>parent;
        vector<int>rank;
        int numComp;
        UF(int n){
            parent=vector<int>(n,0);
            rank=vector<int>(n,0);
            for(int i=0;i<n;i++) parent[i]=i;
            numComp=n;
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
            numComp--;
            return true;
        }
    };
    public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        UF uf=UF(n);
        sort(logs.begin(),logs.end());
        int start=logs[0][0];
        int m=logs.size();
        for(int i=0;i<m;i++){
            uf.unionNodes(logs[i][1],logs[i][2]);
            if(uf.numComp==1) return logs[i][0];
        }
        return -1;
    }
};
