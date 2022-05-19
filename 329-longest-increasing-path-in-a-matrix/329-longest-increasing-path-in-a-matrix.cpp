class Solution {
public:
    int n,m;
    int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
    vector<vector<int>>f,w;
    int dp(int x,int y){
        int& v=f[x][y];
        if(v!=-1) return v;
        v=1;
        for(int i=0;i<4;i++){
            int a=x+dx[i],b=y+dy[i];
            if(a>=0 && a<n && b>=0 && b<m && w[a][b]>w[x][y]) v=max(v,dp(a,b)+1);
        }
        return v;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        w=matrix;
        int res=0;
        n=w.size(),m=w[0].size();
        f=vector<vector<int>>(n,vector<int>(m,-1));
        if(!n || !m) return 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                res=max(res,dp(i,j));
            }
        return res;
    }
};