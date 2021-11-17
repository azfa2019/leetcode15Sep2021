class Solution {
  public:
  vector<int> getBiggestThree(vector<vector<int>>& grid) {
    int m=grid.size(),n=grid[0].size();
    unordered_set<int>set0;
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        set0.insert(grid[i][j]);
        int r=min(i,j);
        r=min(m-1-i,r);
        r=min(n-1-j,r);
        for(int k=1;k<=r;k++){
          int sum=0;
          int i0=i-k;
          int j0=j;
          for(int s=1;s<=k;s++){
            i0++;
            j0--;
            sum+=grid[i0][j0];
          }
          for(int s=1;s<=k;s++){
            i0++;
            j0++;
            sum+=grid[i0][j0];
          }
          for(int s=1;s<=k;s++){
            i0--;
            j0++;
            sum+=grid[i0][j0];
          }
          for(int s=1;s<=k;s++){
            i0--;
            j0--;
            sum+=grid[i0][j0];
          }
          set0.insert(sum);
        }
      }
    }
    vector<int>ans(set0.begin(),set0.end());
    sort(ans.rbegin(),ans.rend());
    while(ans.size()>3) ans.pop_back();
    return ans;
  }
};
//2500* 50