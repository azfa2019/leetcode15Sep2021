
    const int N=75;
int dp[N][N][N];
    int dx[3]={-1,0,1};
class Solution {
public:
    
    int cherryPickup(vector<vector<int>>& g) {
        memset(dp,0,sizeof dp);
        int n=g.size(),m=g[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,0)));
        dp[0][0][m-1]=g[0][0]+g[0][m-1];
        int ans=0;
        for(int i=1;i<n;i++)
            for(int j1=0;j1<m;j1++){
                if(j1>i) continue;
                for(int j2=j1+1;j2<m;j2++){
                    if(j2<m-1-i) continue;
                    for(int d1=0;d1<3;d1++)
                        for(int d2=0;d2<3;d2++){
                            int p1=j1+dx[d1],p2=j2+dx[d2];
                            if(p1<0||p1>=m||p2<0||p2>=m) continue;
                            if(j1==j2) dp[i][j1][j2]=max(dp[i][j1][j2],dp[i-1][p1][p2]+g[i][j1]);
                            else dp[i][j1][j2]=max(dp[i][j1][j2],dp[i-1][p1][p2]+g[i][j1]+g[i][j2]);
                        }
                }
            }
                                                   
        for(int a=0;a<m;a++)
            for(int b=a+1;b<m;b++)
                ans=max(ans,dp[n-1][a][b]);
        return ans;
    }
};