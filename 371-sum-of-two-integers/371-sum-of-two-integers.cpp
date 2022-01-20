class Solution {
public:
    int getSum(int a, int b) {
        while(b){
            uint32_t aTmp=a,bTmp=b;
            a=(aTmp^bTmp);
            b=(aTmp&bTmp)<<1;
        }
        return a;
    }
};