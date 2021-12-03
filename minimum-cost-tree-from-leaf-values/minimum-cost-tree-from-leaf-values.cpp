class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        vector<vector<int>>large(n,vector<int>(n,INT_MIN));
        int sum=0;
        for(int i=0;i<n;i++){
            dp[i][i]=arr[i];
            large[i][i]=arr[i];
            sum+=arr[i];
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                for(int k=i;k<j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+large[i][k]*large[k+1][j]);
                    large[i][j]=max(large[i][k],large[k+1][j]);
                }
            }
        }
        return dp[0][n-1]-sum;
    }
};