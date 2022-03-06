class Solution {
public:
    int countOrders(int n) {
        long long res=1;
        int mod=1e9+7;
        for(int i=1;i<=2*n;i++){
            res=res*(i%2?i:i/2)%mod;
        }
        return res%mod;
    }
};