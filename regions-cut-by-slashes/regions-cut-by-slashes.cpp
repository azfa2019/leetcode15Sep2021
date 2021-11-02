class Solution {
  int n;
  vector<int>parent;
  public:
  int regionsBySlashes(vector<string>& grid) {
    n=grid.size();
    parent.resize((n+1)*(n+1));
    for(int i=0;i<=n;i++)
      for(int j=0;j<=n;j++){
        int idx=i*(n+1)+j;
        parent[idx]=idx;
        if(i==0||j==0||i==n||j==n) parent[idx]=0;
      }
    int count=1;
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++){
        int a,b;
        if(grid[i][j]==' ') continue;
        else if(grid[i][j]=='/') {
          a=node(i+1,j);
          b=node(i,j+1);
        }else{
          a=node(i+1,j+1);
          b=node(i,j);
        }
        if(findParent(a)==findParent(b)) count++;
        else unionNodes(a,b);
      }
    return count;
  }
  int node(int i,int j){
    return i*(n+1)+j;
  }
  int findParent(int n){
    if(parent[n]!=n) parent[n]=findParent(parent[n]);
    return parent[n];
  }
  void unionNodes(int n1,int n2){
    int p1=parent[n1];
    int p2=parent[n2];
    if(p1<p2) parent[p2]=p1;
    else parent[p1]=p2;
  }
};
