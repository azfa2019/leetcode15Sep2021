class Solution {
public:
    int hammingDistance(int x, int y) {
      int count=0;
      for(int i=0;i<32;i++){
        int xbit=(x>>i)&1;
        int ybit=(y>>i)&1;
        if(xbit!=ybit) count++;
      }
      return count;
    }
};