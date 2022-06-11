class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int l=0,sum=0,r=0,n=nums.size();
        int ans=-1;
        int t=accumulate(nums.begin(),nums.end(),0)-x;
        while(r<n){
            sum+=nums[r];
            while(sum>t && l<=r) sum-=nums[l++];
            if(sum==t) ans=max(ans,r-l+1);
            r++;
        }
        return ans==-1?-1:n-ans;
    }
};