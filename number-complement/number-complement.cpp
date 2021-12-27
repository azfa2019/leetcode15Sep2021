class Solution {
    public:
    int findComplement(int num) {
        int n=num;
        int bitCount=0;
        while(n>0) {
            bitCount++;
            n=(n>>1);
        }
        int tmp=pow(2,bitCount)-1;
        return num^tmp;
    }
};