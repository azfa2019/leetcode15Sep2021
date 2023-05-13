class Solution {
public:
    int f[100010];
    int countGoodStrings(int low, int high, int zero, int one) {
        int mod=1e9+7;
        int ans=0;
        
        //for(int i=0;i<20;i++) cout<<f[i]<<endl;
        f[zero]+=1;
        f[one]+=1;
        for(int i=1;i<=high;i++){
            if(i>=zero) f[i]=(f[i]+f[i-zero])%mod;
            if(i>=one) f[i]=(f[i]+f[i-one])%mod;
        }
        for(int i=low;i<=high;i++) ans=(ans+f[i])%mod;
        return ans;
    }
};