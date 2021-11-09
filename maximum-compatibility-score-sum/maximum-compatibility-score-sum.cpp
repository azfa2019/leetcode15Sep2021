typedef pair<int,int> PII;
class Solution {
  int m,n;
  int unmatch[8][8];
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
      int m=students.size(),n=students[0].size();
      for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
          int total=0;
          for(int k=0;k<n;k++) 
            total+=students[i][k]==mentors[j][k];
          unmatch[i][j]=n-total;
        }
      }
      
      priority_queue<PII,vector<PII>,greater<>> pq;
      //pq saves {cost,state}
      pq.push({0,0}); 
      vector<int>dp(1<<m,-1);
      while(!pq.empty()){
        auto [cost,state]=pq.top();
        pq.pop();
        
        if(dp[state]!=-1) continue;
        dp[state]=cost;
        if(state==((1<<m)-1)) return m*n-cost;
        
        int j=__builtin_popcount(state);
        for(int i=0;i<m;i++){
          if (((state>>i)&1)==1) continue;
          int newstate=state+(1<<i);
          if(dp[newstate]!=-1) continue;
          pq.push({cost+unmatch[i][j], newstate});
        }
      }
      return -1;
    }
};