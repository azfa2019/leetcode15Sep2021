typedef long long LL;
const int mod=1e9+7;
class Solution {
    int cnt[310];
public:
    LL C(int a,int b){
        LL res=1;
        for(int i=a,j=1;j<=b;j++,i--)
            res=(res*i/j)%mod;
        return res;
    }
    int calc(int a,int b,int c){
        if(a==b && b==c) return C(cnt[a],3);
        if(a==b) return C(cnt[a],2)*cnt[c]%mod;
        if(b==c) return C(cnt[b],2)*cnt[a]%mod;
        return (LL) cnt[a]*cnt[b]*cnt[c]%mod;
    }
    int threeSumMulti(vector<int>& arr, int target) {
        int res=0;
        for(auto x:arr) cnt[x]++;
        for(int i=0;i<=target;i++)
            for(int j=i;j<=target-i-j;j++)
                res=(res+calc(i,j,target-i-j))%mod;
    return res;
    }
};
