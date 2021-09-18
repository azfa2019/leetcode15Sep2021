class Solution {
  public:
  int dir[5][2]={{-1,0},{1,0},{0,-1},{0,1},{0,0}};
  int encode(vector<vector<int>>&mat,int m,int n){
    int x=0;
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
        x=x*2+mat[i][j];
    return x;
  }
  vector<vector<int>> decode(int x,int m,int n){
    vector<vector<int>>mat(m,vector<int>(n));
    for(int i=m-1;i>=0;i--)
      for(int j=n-1;j>=0;j--){
        mat[i][j]=x&1;
        x=(x>>1);
      }
    return mat;
  }
  void convert(vector<vector<int>>&mat,int m,int n,int i,int j){
    for(int k=0;k<5;k++){
      int i0=i+dir[k][0],j0=j+dir[k][1];
      if(i0>=0 && i0<m && j0>=0 && j0<=n-1) mat[i0][j0]^=1;
    }
  }
  int minFlips(vector<vector<int>>& mat) {
    int m=mat.size(),n=mat[0].size();
    int xstart=encode(mat,m,n),step=0;
    if(xstart==0) return step;
    unordered_set<int> visited;
    queue<int>q;
    visited.insert(xstart);
    q.push(xstart);
    while(!q.empty()){
      ++step;
      int qsize=q.size();
      for(int k=0;k<qsize;k++){
        auto curmat=decode(q.front(),m,n);
        q.pop();
        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
            convert(curmat,m,n,i,j);
            int curnum=encode(curmat,m,n);
            if(curnum==0) return step;
            if(visited.find(curnum)==visited.end()){
              visited.insert(curnum);
              q.push(curnum);
            }
            convert(curmat,m,n,i,j);
          }
        }
      }
    }
    return -1;
  }
};