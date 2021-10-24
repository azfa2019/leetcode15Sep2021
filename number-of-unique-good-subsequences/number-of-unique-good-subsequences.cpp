using ll=long long;
class Solution {
  ll M=1e9+7;
public:
    int numberOfUniqueGoodSubsequences(string binary) {
      //dp[i]=dp[i-1]*2-dp[j] if(binary[j]==binary[i]) the most close j
      //dp[i]: # of unique subseq for binary[1:i]
      //dp[0]: empty string, =1
      int n=binary.size();
      binary="#"+binary;
      vector<ll>dp(n+1,0);
      int m=1;
      while(m<=n && binary[m]=='0') m++;
      if(m==n+1) return 1;
      dp[m]=1;
      vector<int>last(2,0);
      for(int i=m+1;i<=n;i++){
        int j=last[binary[i]-'0'];
        dp[i]=2*dp[i-1]%M-(j>=1?dp[j-1]:0);
        dp[i]+=M;
        dp[i]%=M;
        //if(binary[i]=='0') dp[i]=dp[i]-dp[i-1]+1;
        last[binary[i]-'0']=i;
      }
      return dp[n]+(binary.find("0")!=-1);
    }
};