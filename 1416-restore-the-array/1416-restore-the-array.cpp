typedef long long LL;
const LL mod=1e9+7;
class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n=s.size();
        vector<LL>f(n+1);
        f[n]=1;
        for(int i=n-1;i>=0;i--){
            LL x=0;
            if(s[i]=='0') {
                f[i]=0;
                continue;
            }
            for(int j=i;j<n;j++){
                x=x*10+s[j]-'0';
                if(x<=k) f[i]=(f[i]+f[j+1])%mod;
                else break;
            }
        }
        return (int)f[0];
    }
};