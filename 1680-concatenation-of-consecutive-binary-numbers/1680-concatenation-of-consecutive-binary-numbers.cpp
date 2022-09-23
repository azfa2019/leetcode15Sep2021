class Solution {
public:
    int concatenatedBinary(int n) {
        int bit=0;
        long long res=0;
        const int mod=1e9+7;
        for(int i=1;i<=n;i++){
            if((i&(i-1))==0) bit++;
            res=((res<<bit)+i)%mod;
        }
        return res;
    }
};