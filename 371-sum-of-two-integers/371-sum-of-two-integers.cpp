class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            uint32_t atmp=a;
            a=(atmp^b);
            b=((atmp&b)<<1);
        }
        return a;
    }
};