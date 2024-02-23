class Solution {
public:
    int res=0;
    int treeDiameter(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>>g(n+1);
        for(auto& e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs(g,0,-1);
        return res;
    }
    int dfs(vector<vector<int>>&g,int cur,int prev){
        auto list=g[cur];
        int mx1=0,mx2=0;
        for(int nei:list){
            if(nei!=prev){
                int mx=dfs(g,nei,cur)+1;
                if(mx>=mx1) {
                    mx2=mx1;
                    mx1=mx;
                }else if(mx>=mx2)
                    mx2=mx;
                res=max(res,mx1+mx2);
            }
        }
        return mx1;
    }
};