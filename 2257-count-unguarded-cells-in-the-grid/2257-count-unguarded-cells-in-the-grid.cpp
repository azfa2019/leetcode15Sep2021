class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>visited(m,vector<int>(n,-1));
        for(auto w:walls) visited[w[0]][w[1]]=0;
        for(auto w:guards) visited[w[0]][w[1]]=0;
        for(auto g:guards){
            int i=g[0],j=g[1];
            dfs(visited,i-1,j,-1,0);
            dfs(visited,i+1,j,1,0);
            dfs(visited,i,j-1,0,-1);
            dfs(visited,i,j+1,0,1);
        }
        int cnt=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(visited[i][j]==-1) cnt++;
        return cnt;
    }
    void dfs(vector<vector<int>>& visited,int i,int j,int dx,int dy){
        if(i<0||i>=visited.size()||j<0||j>=visited[0].size()||visited[i][j]==0) return;
        visited[i][j]=1;
        dfs(visited,i+dx,j+dy,dx,dy);
    }
};