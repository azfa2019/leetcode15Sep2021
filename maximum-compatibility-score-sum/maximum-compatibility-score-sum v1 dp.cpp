class Solution {
  int m,n;
  int match[8][8];
  public:
  int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
    m=students.size(),n=students[0].size();
    for(int i=0;i<m;i++){
      for(int j=0;j<m;j++){
        int count=0;
        for(int k=0;k<n;k++) 
          count+=(students[i][k]==mentors[j][k]);
        match[i][j]=count;
      }
    }
    vector<int>dp(1<<m);
    //dp[state]: max score, when first i students and i mentors are matched, i is the # of 1 bits in state
    for(int j=0;j<m;j++){ //j is mentor index
      int state=(1<<(j+1))-1; //there are j+1 mentors that have been matched with students
      while(state<(1<<m)){
        for(int i=0;i<m;i++){// ith bit=1 means picking student i 
          if(((state>>i)&1)==0) continue;
          dp[state]=max(dp[state],dp[state-(1<<i)]+match[i][j]);
        }

        int c = state & - state;
        int r = state + c;
        state = (((r ^ state) >> 2) / c) | r;
      }
    }
    return dp[(1<<m)-1];//when all students are picked, m 1-bits
  }
};
