class Solution {
public:
    int minCost(vector<int>& h, vector<vector<int>>& cost, int m, int n, int t) {
        //dp[i][j][k]: min cost of: first i houses, j neighborhoods, color k
        int dp[m][t+1][n+1];
        memset(dp,0x3f,sizeof(dp));
        if(h[0]==0)
            for(int k=1;k<=n;k++) dp[0][1][k]=cost[0][k-1];
        else
            dp[0][1][h[0]]=0;
        for(int i=1;i<m;i++){
            if(h[i]==0){
                for(int c=1;c<=n;c++)
                    for(int pc=1;pc<=n;pc++)
                        for(int j=1;j<=t;j++){
                            if(c==pc)
                                dp[i][j][c]=min(dp[i][j][c],dp[i-1][j][c]+cost[i][c-1]);
                            else
                                dp[i][j][c]=min(dp[i][j][c],dp[i-1][j-1][pc]+cost[i][c-1]);
            }
        }else{
                int c=h[i];
                for(int pc=1;pc<=n;pc++)
                    for(int j=1;j<=t;j++){
                        if(c==pc) 
                            dp[i][j][c]=min(dp[i][j][c],dp[i-1][j][c]);
                        else
                            dp[i][j][c]=min(dp[i][j][c],dp[i-1][j-1][pc]);
                    }
            }
        }
        int ans=*min_element(dp[m-1][t],dp[m-1][t]+n+1);
        return ans==0x3f3f3f3f?-1:ans;
    }
};