class Solution {
  unordered_map<int,int>map0;
public:
    int numTrees(int n) {
      if(n<=1) return 1;
      if(map0.find(n)!=map0.end()) return map0[n];
      int count=0;
      for(int i=1;i<=n;i++){
        int left=numTrees(i-1);
        int right=numTrees(n-i);
        count+=left*right;
      }
      return map0[n]=count;
    }
};