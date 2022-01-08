class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MIN));
        dp[0][n-1]=grid[0][0]+grid[0][n-1];
        for(int r=1;r<m;r++){
            auto dpTmp=dp;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    for(int a=i-1;a<=i+1;a++){
                        for(int b=j-1;b<=j+1;b++){
                            if(a<0||b<0||a>n-1||b>n-1) continue;
                            if(i!=j)
                                dp[i][j]=max(dp[i][j],dpTmp[a][b]+grid[r][i]+grid[r][j]);
                            else
                                dp[i][j]=max(dp[i][j],dpTmp[a][b]+grid[r][i]);
                        }
                    }
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                ans=max(ans,dp[i][j]);
        return ans;
    }
};
