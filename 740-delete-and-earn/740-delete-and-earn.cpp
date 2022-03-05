const int N=10010;
int f[N][2],cnt[N];
class Solution {
    public:
    int deleteAndEarn(vector<int>& nums) {
        memset(f,0,sizeof f);
        memset(cnt,0,sizeof cnt);
        for(int num:nums) cnt[num]++;
        int res=0;
        //int maxNum=*max_element(nums.begin(),nums.end());
        for(int i=1;i<N;i++){
            f[i][1]=f[i-1][0]+i*cnt[i];
            f[i][0]=max(f[i-1][0],f[i-1][1]);
            //res=max(f[i][0],f[i][1]);
        }
        return max(f[N-1][0],f[N-1][1]);
    }
};