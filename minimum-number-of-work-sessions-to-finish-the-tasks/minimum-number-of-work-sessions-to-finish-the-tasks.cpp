class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
      int n=tasks.size();
      int m=(1<<n);
      vector<int>dp(m,INT_MAX/2);
      for(int state=1;state<m;state++){
        int sum=0;
        for(int i=0;i<n;i++)
          if((state>>i)&1) sum+=tasks[i];
        if(sum<=sessionTime) dp[state]=1;
      }
      for(int state=1;state<m;state++){
        int bound=state>>1;
        for(int subset=state;subset>bound;subset=(subset-1)&state){
          dp[state]=min(dp[state],dp[subset]+dp[state-subset]);
        }
      }
      return dp[m-1];
        
    }
};