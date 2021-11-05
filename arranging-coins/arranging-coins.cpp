class Solution {
public:
    int arrangeCoins(int n) {
      int i=0;
      if(n==1) return 1;
      while(true){
        i++;
        n-=i;
        if(n<0) break;
      }
      return i-1;
    }
};