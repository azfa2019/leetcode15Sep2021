class Solution {
  public:
  int minimumMoves(vector<int>& arr) {
    int n=arr.size();
    arr.insert(arr.begin(),0);
    vector<vector<int>>dp(n+1,vector<int>(n+1,INT_MAX/2));
    dp[0][0]=0;
    //min # of moves to remove arr[i][j]
    for(int i=1;i<n;i++) dp[i][i]=1;
    // zzz i xxxkxxx j yyy
    //len=2:j=i+1<=n, j=n, k=j=n, k+1=n+1
    //len=n: i<=n, j=i+len-1=i+n-1<=n, i-1<=0
    for(int len=2;len<=n;len++){
      for(int i=1;i+len-1<=n;i++){
        int j=i+len-1;
        dp[i][j]=dp[i][j-1]+1;
        for(int k=i;k<=j;k++){
          if(arr[k]==arr[j]) dp[i][j]=min(dp[i][j],(i>k-1?0:dp[i][k-1])+max(1,(k+1>j-1?0:dp[k+1][j-1])));
          //k=j, k=i, 
        }
      }
    }
    return dp[1][n];
  }
};