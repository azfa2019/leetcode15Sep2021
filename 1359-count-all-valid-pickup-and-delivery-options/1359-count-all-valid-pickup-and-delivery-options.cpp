class Solution {
public:
    int mod=1e9+7;
    int countOrders(int n) {
        long long res=1;
        for(int i=1;i<=2*n;i++){
            if(i%2) res*=i;
            else res*=i/2;
            res%=mod;
        }
        return (int)res;
    }
};