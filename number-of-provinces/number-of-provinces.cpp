class Solution {
    class UF{
        public:
        vector<int>parent;
        vector<int>rank;
        UF(int n){
            parent=vector<int>(n,0);
            for(int i=0;i<n;i++) parent[i]=i;
            rank=vector<int>(n,0);
        }
        int findParent(int x){
            if(x!=parent[x]) parent[x]=findParent(parent[x]);
            return parent[x];
        }
        bool unionNodes(int x,int y){
            x=findParent(x);
            y=findParent(y);
            if(x==y) return false;
            if(rank[x]>rank[y]) parent[y]=x;
            else if(rank[x]<rank[y]) parent[x]=y;
            else{
                parent[x]=y;
                rank[y]++;
            }
            return true;
        }
    };
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        UF uf=UF(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(isConnected[i][j]==1) uf.unionNodes(i,j);
            }
        }
        unordered_set<int>st;
        for(int i=0;i<n;i++)
            st.insert(uf.findParent(i));
        return st.size();
    }
};