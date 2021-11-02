class Solution {
  vector<int>parent;
  int n;
  public:
  int regionsBySlashes(vector<string>& grid) {
    n=grid.size();
    parent.resize((n+1)*(n+1));
    for(int i=0;i<=n;i++)
      for(int j=0;j<=n;j++){
        int idx=i*(n+1)+j;
        parent[idx]=idx;
        if(i==0||i==n||j==0||j==n) parent[idx]=0;
      }
    int count=1;
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++){
        if(grid[i][j]==' ') continue;
        int a,b;
        if(grid[i][j]=='/'){
          a=node(i,j+1);
          b=node(i+1,j);
        }else{
          a=node(i,j);
          b=node(i+1,j+1);
        }
        if(find(a)==find(b)) count++;
        else unionNodes(a,b);
      }
    return count;
  }
  int node(int i,int j){
    return i*(n+1)+j;
  }
  int find(int x){
    if(parent[x]!=x) parent[x]=find(parent[x]);
    return parent[x];
  }
  void unionNodes(int a, int b){
    a=parent[a];
    b=parent[b];
    if(a<b) parent[b]=a;
    else    parent[a]=b;
  }
};