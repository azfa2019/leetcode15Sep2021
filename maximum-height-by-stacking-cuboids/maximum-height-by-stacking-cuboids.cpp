class Solution {
  public:
  int maxHeight1(vector<vector<int>>& cuboids) {
    //dp[i-1] dp[i]=dp[j]+cuboids[i] height 
    int n=cuboids.size();
    vector<array<int,4>>shapes;
    for(int i=0;i<n;i++){
      int l=cuboids[i][0];
      int w=cuboids[i][1];
      int h=cuboids[i][2];
      shapes.push_back({l,w,h,i});
      shapes.push_back({l,h,w,i});
      shapes.push_back({w,l,h,i});
      shapes.push_back({w,h,l,i});
      shapes.push_back({h,w,l,i});
      shapes.push_back({h,l,w,i});
    }
    sort(shapes.begin(),shapes.end());
    int m=6*n;
    vector<int>dp(m,0);
    for(int i=0;i<m;i++){
      dp[i]=shapes[i][2];
      for(int j=0;j<i;j++){
        if(shapes[i][0]>=shapes[j][0] && shapes[i][1]>=shapes[j][1] && shapes[i][2]>=shapes[j][2] &&  shapes[i][3]!=shapes[j][3] )
          dp[i]=max(dp[i],dp[j]+shapes[i][2]);
      }
    }
    int ans=0;
    for(int i=0;i<m;i++)
      ans=max(ans,dp[i]);
    return ans;
  }
  int maxHeight(vector<vector<int>>& cuboids) 
    {
        int n = cuboids.size();
        vector<array<int,4>>p;
        for (int i=0; i<cuboids.size(); i++)
        {
            auto c = cuboids[i];
            p.push_back({c[0], c[1], c[2], i});
            p.push_back({c[0], c[2], c[1], i});
            p.push_back({c[1], c[0], c[2], i});
            p.push_back({c[1], c[2], c[0], i});
            p.push_back({c[2], c[0], c[1], i});
            p.push_back({c[2], c[1], c[0], i});
        }
        sort(p.begin(), p.end());
        vector<int>dp(6*n);
        for (int i=0; i<6*n; i++)
        {
            dp[i] = p[i][2];
            for (int j=0; j<i; j++)
                if (p[j][0]<=p[i][0] && p[j][1]<=p[i][1] && p[j][2]<=p[i][2] && p[j][3]!=p[i][3])
                    dp[i] = max(dp[i], dp[j]+p[i][2]);
        }

        int ret = 0;
        for (int i=0; i<6*n; i++)
            ret = max(ret, dp[i]);        
        return ret;
    }
};