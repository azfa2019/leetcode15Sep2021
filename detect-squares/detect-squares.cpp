class DetectSquares {
  int counts[1001][1001];
  public:
  DetectSquares() {
    for(int i=0;i<=1000;i++)
      for(int j=0;j<=1000;j++)
        counts[i][j]=0;
  }

  void add(vector<int> point) {
    counts[point[0]][point[1]]++;

  }

  int count(vector<int> point) {
    int x=point[0],y=point[1];
    int ans=0;
    for(int u=0;u<=1000;u++){
      int d=abs(x-u);
      if(d==0) continue;
      int v=y+d;
      if(v>=0&& v<=1000)
        ans+=counts[u][v]*counts[u][y]*counts[x][v];
      v=y-d;
      if(v>=0&& v<=1000)
        ans+=counts[u][v]*counts[u][y]*counts[x][v];
    }
    return ans;
  }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */