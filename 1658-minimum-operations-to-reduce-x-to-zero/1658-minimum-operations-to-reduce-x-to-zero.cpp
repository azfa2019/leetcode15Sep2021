class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int l=0,r=0,sum=0;
        int t=accumulate(nums.begin(),nums.end(),0)-x;
        int ans=-1;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>t && l<=r) sum-=nums[l++];
            if(sum==t) ans=max(ans,r-l+1);
            r++;
        }
        return ans==-1?-1:nums.size()-ans;
    }
};