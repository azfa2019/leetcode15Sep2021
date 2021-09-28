class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
      int m=mat.size(),n=mat[0].size();
      int maxsum=0;
      vector<int>f{1};//f[j]: you can get a sum j from the first i rows. When no row is selected, you can get a sum of 0. So f is initialized as {1}
      for(int i=0;i<m;i++){
        int best=*max_element(mat[i].begin(),mat[i].end());
        vector<int>g(maxsum+best+1);// here 1 is the first 1 {1}
        for(int x:mat[i]){
          for(int j=x;j<=maxsum+x;++j)
            g[j]|=f[j-x];
        }
        f=move(g);
        maxsum+=best;//maintain a maxsum, this is to reduce the search domain
      }
      int ans=INT_MAX;
      for(int i=0;i<=maxsum;++i){
        if(f[i]&&abs(i-target)<ans) ans=abs(i-target);
      }
      return ans;
    }
};