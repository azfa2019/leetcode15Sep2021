class Solution1 {
  public:
  unordered_map<int,int>map0;
  int numTrees(int n) {//71
    if(n<=1) return 1;
    if(map0.find(n)!=map0.end()) return map0[n];
    int count=0;
    for(int i=0;i<n;i++){
      int left=numTrees(i-1);
      int right=numTrees(n-i);
      count+=left*right;
    }
    return map0[n]=count;
  }
};
class Solution {
    public:
    unordered_map<int,int>m;
    int numTrees(int n) {//00
        //memoization + recursive
        if(n<=1) return 1;
        if(m.count(n)) return m[n];
        int count=0;
        for(int i=1;i<=n;i++){
            int left=numTrees(i-1);
            int right=numTrees(n-i);
            count+=left*right;
        }
        return m[n]=count;
    }
};