/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int can=0;
        for(int j=1;j<n;j++)
            if(knows(can,j)) can=j;
        for(int k=0;k<n;k++){
            if(can==k) continue;
            if(knows(can,k)||!knows(k,can)) return -1;
        }
        return can;
    }
};