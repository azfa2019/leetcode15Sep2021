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
    int u=point[0],v=point[1];
    int ans=0;
      for(int x=0;x<=1000;x++){
        int d=abs(x-u);
        if(d==0) continue;
        int y=v+d;
        if(y<=1000 && y>=0)
          ans+=counts[u][y]*counts[x][y]*counts[x][v];
        y=v-d;
        if(y<=1000 && y>=0)
          ans+=counts[u][y]*counts[x][y]*counts[x][v];
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