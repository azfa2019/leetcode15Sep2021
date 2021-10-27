class Solution {
  int count;
  int digits[10];
  public:
  int numDupDigitsAtMostN(int n) {
    for(int i=1;i<=9;i++){
      digits[i]=1;
      dfs(n,i);
      digits[i]=0;
    }
    return n-count;
  }
  void dfs(int n,long cur){
    if(cur>n) return;
    count++;
    for(int i=0;i<=9;i++){
      if(digits[i]==0){
        digits[i]++;
        dfs(n,cur*10+i);
        digits[i]--;
      }
    }
  }
};
// 11 2
// 11 3
// 12 2