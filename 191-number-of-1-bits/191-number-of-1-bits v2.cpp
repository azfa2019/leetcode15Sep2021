class Solution {
    int lowbit(uint32_t n){
        return n&(-n);
    }
public:
    int hammingWeight(uint32_t n) {
        uint32_t count=0;
        while(n){
            n=n-lowbit(n);
            count++;
        }
        return count;
    }
};
