class Solution {
  public:
  int tallestBillboard(vector<int>& rods) {
    int offset=0;
    for(int r:rods) offset+=r;
    int n=rods.size();
    vector<int>dp(2*offset+1,-1);
    //dp[i][j]: the tallest of height of left rod when difference between left and right is j
    dp[0+offset]=0;
    for(int i=0;i<n;i++){
      int l=rods[i];
      auto dpOld=dp;
      for(int diff=-offset;diff<=offset;diff++){
        if(dpOld[diff+offset]==-1) continue; //not possible
        if(diff+offset+l<=offset*2)
          dp[diff+offset+l]=max(dp[diff+offset+l],dpOld[diff+offset]+l); //put the new rod at left
        if(diff+offset-l>=0)
          dp[diff+offset-l]=max(dp[diff+offset-l],dpOld[diff+offset]);//put the new rod at right
      }
    }
    //cout<<n<<sum<<endl;
    return dp[0+offset];
  }
};