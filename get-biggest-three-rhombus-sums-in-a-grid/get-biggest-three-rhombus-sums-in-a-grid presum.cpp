class Solution {
  int presum1[100][100]; // "\"
  int presum2[100][100]; // "/"
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
      int m=grid.size(),n=grid[0].size();
      for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
          presum1[i][j]=((i-1>=0 && j-1>=0)?presum1[i-1][j-1]:0)+grid[i][j];
        
      for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
          presum2[i][j]=((i-1>=0 && j+1<n)?presum2[i-1][j+1]:0)+grid[i][j];
      
      unordered_set<int>set0;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          set0.insert(grid[i][j]);
          int rmax=min(i,j);
          rmax=min(rmax,m-1-i);
          rmax=min(rmax,n-1-j);
          for(int r=1;r<=rmax;r++){
            int sum=0;
            int i0,j0,i1,j1;
            i0=i-r;
            j0=j;
            i1=i;
            j1=j+r;
            sum+=presum1[i1][j1]-((i0-1>=0&&j0-1>=0)?presum1[i0-1][j0-1]:0);
            
            i0=i;
            j0=j-r;
            i1=i+r;
            j1=j;
            sum+=presum1[i1][j1]-((i0-1>=0&&j0-1>=0)?presum1[i0-1][j0-1]:0);
            
            i0=i-r;
            j0=j;
            i1=i;
            j1=j-r;
            sum+=presum2[i1-1][j1+1]-presum2[i0][j0];
            
            i0=i;
            j0=j+r;
            i1=i+r;
            j1=j;
            sum+=presum2[i1-1][j1+1]-presum2[i0][j0];
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
