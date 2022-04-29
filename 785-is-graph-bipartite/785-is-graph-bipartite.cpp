const int N=110;
class Solution {
   
    int color[N];
    bool dfs( vector<vector<int>>&g,int u,int c){
        color[u]=c;
        for(auto i:g[u]){
            if(!color[i]){
                if(!dfs(g,i,3-c)) return false;
            }else if(color[i]==c) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        bool flag=true;
        for(int i=0;i<n;i++){
            if(!color[i]){
                if(!dfs(graph,i,1)) {
                    flag=false;
                    break;
                }
            }
        }
        if(flag) return true;
        return false;
    }
};