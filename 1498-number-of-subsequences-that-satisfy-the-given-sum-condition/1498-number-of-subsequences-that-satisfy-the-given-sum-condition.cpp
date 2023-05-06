class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int mod=1e9+7;
        const int N=1e5+5;
        int p[N];
        int n=nums.size();
        p[0]=1;
        for(int i=1;i<N;i++) p[i]=p[i-1]*2%mod;
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n;i++){
            int mv=target-nums[i];
            int pos=upper_bound(nums.begin(),nums.end(),mv)-nums.begin()-1;
            ans+=(pos>=i)?p[pos-i]:0;
            ans%=mod;
        }
        return ans;
    }
};