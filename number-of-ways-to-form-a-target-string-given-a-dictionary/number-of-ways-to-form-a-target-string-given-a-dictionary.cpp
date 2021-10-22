class Solution {
  long dp[1001][1001];
  long M=1e9+7;
  long count[1001][27];
  public:
  int numWays(vector<string>& words, string target) {
    //dp[k][i]: # of ways , using chars up to position k of words, to form i character of target
    //k: word, K
    //i: target, n
    // target: a b a
    //           i
    // dp[k][i] += dp[k-1][i-1] if target[i]==words[j][k]
    // dp[k][i] += dp[k-1][i]  do nothing with k of words
    int K=words[0].size(),n=target.size();
    target="#"+target;
    for(string word:words){
      for(int k=0;k<K;k++) count[k+1][word[k]-'a']++;
    }
    for(int k=0;k<=K;k++) dp[k][0]=1;
    //for(int i=0;i<=n;i++) dp[0][i]=0;
    for(int k=1;k<=K;k++){
      for(int i=1;i<=n;i++){
        //cout<<i<<" "<<k<<endl;
        dp[k][i]=dp[k-1][i];
        if(count[k][target[i]-'a']>0)
          dp[k][i]+=dp[k-1][i-1]*count[k][target[i]-'a']%M;
        //cout<<dp[k][i]<<endl;
        dp[k][i]%=M;
      }
    }
    return dp[K][n];
  }
};