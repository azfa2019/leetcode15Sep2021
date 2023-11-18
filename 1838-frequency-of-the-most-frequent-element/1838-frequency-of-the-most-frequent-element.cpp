class Solution {
public:
    typedef long long LL;
    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0,ans=1;
        LL sum=0;
        for(int i=1;i<n;i++){
            sum+=(LL)(nums[i]-nums[i-1])*(i-l);
            while(sum>k) sum-=nums[i]-nums[l++];
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};