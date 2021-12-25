class Solution {
public:
    int getSum(int a, int b) {
        int a0,b0;
        while(b!=0){
            a0=a;
            b0=b;
            a=(a0^b0);
            b=((unsigned int)(a0&b0)<<1);
        }
        return a;
    }
};