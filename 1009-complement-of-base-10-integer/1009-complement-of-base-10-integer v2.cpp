class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int num=n;
        int count=0;
        while(num!=0) count++,num=(num>>1);
        int tmp=pow(2,count)-1;
        return n^tmp;
    }
};
