typedef long long LL;
class Solution {
public:
    long long subsequenceSumOr(vector<int>& nums) {
        vector<LL>cnt(64);
        LL ans=0;
        for(int& n:nums){
            for(int i=0;i<31;i++)
                if(n>>i&1) cnt[i]++;
        }
        for(int i=0;i<63;i++){
            if(cnt[i]) ans|=1LL<<i;
            cnt[i+1]+=cnt[i]/2;
        }
        return ans;
    }
};