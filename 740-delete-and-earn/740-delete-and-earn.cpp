const int N=10010;
int f[N][2],cnt[N];
class Solution {
    public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        memset(f,0,sizeof f);
        memset(cnt,0,sizeof cnt);
        int res=0;
        for(int num:nums) cnt[num]++;
        for(int i=1;i<N;i++){
            f[i][0]=max(f[i-1][1],f[i-1][0]);
            f[i][1]=f[i-1][0]+i*cnt[i];
            res=max(res,max(f[i][0],f[i][1]));
        }
        return res;
    }
};