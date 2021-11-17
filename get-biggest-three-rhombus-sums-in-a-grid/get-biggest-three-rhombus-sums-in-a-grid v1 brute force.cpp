class Solution {
  public:
  vector<int> getBiggestThree(vector<vector<int>>& grid) {
    int m=grid.size(),n=grid[0].size();
    unordered_set<int>set0;
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        int r= min(i,j);
        r=min(r,m-1-i);
        r=min(r,n-1-j);
        set0.insert(grid[i][j]);
        for(int k=1;k<=r;k++){
          int count=0;
          int topi=i-k;
          int topj=j;
          for(int u=1;u<=k;u++){
            topi++;
            topj--;
            count+=grid[topi][topj];
          }
          for(int u=1;u<=k;u++){
            topi++;
            topj++;
            count+=grid[topi][topj];
          }
          for(int u=1;u<=k;u++){
            topi--;
            topj++;
            count+=grid[topi][topj];
          }
          for(int u=1;u<=k;u++){
            topi--;
            topj--;
            count+=grid[topi][topj];
          }
          set0.insert(count);
        }
      }
    }
    //cout<<"hi"<<endl;
    vector<int>ans(set0.begin(),set0.end());
    sort(ans.rbegin(),ans.rend());
    while(ans.size()>3) ans.pop_back();
    return ans;
  }
};
//2500* 50
