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
            int p1=findParent(n1);
            int p2=findParent(n2);
            if(p1==p2) return false;
            if(rank[p1]<rank[p2]) parent[p1]=p2;
            else if(rank[p1]>rank[p2]) parent[p2]=p1;
            else parent[p2]=p1,rank[p1]++;
            return true;
        }
        int findParent(int n){
            if(n!=parent[n]) parent[n]=findParent(parent[n]);
            return parent[n];
        }
    };
    public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UF uf=UF(n);
        for(auto e:edges){
            uf.unionNodes(e[0],e[1]);
        }
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            st.insert(uf.findParent(i));
        }
        return st.size();
    }
};