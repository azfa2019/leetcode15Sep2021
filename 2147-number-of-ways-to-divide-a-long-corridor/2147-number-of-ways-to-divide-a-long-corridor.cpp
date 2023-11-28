class Solution {
public:
    int numberOfWays(string corridor) {
        const int mod=1e9+7;
        int ans=1,cnts=0,pre=0;
        for(int i=0;i<corridor.size();i++){
            if(corridor[i]=='S'){
                cnts++;
                if(cnts>=3&&cnts%2) ans=(long)ans*(i-pre)%mod;
                pre=i;
            }
        }
        return cnts&&cnts%2==0?ans:0;
    }
};