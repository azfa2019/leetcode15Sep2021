class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
      int m=cuts.size();
      sort(cuts.begin(),cuts.end());
      cuts.insert(cuts.begin(),0);
      cuts.push_back(n);
      vector<vector<int>>dp(m+2,vector<int>(m+2,INT_MAX));
      for(int i=0;i<m+1;i++) dp[i][i+1]=0;
      //dp[i][j]: minimum score when cutting interval i:j, when doing cuts[i] followed by cuts[j]
      for(int len=3;len<=m+2;len++){ //len is the length in cuts, not n
        for(int i=0;i+len-1<=m+1;i++){
          int j=i+len-1;
          for(int k=i+1;k<=j-1;k++){
            //cout<<i<<","<<j<<","<<k<<""<<endl;
            dp[i][j]=min(dp[i][j],cuts[j]-cuts[i]+dp[i][k]+dp[k][j]);
          }
        }
      }
      return dp[0][m+1];
    }
};