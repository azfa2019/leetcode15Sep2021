class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int n=nums.size(),mini=-1,maxi=-1,i0=-1;
        for(int i=0;i<n;i++){
            int x=nums[i];
            if(x==minK) mini=i;
            if(x==maxK) maxi=i;
            if(x<minK ||x>maxK) i0=i;
            ans+=max(min(mini,maxi)-i0,0);
        }
        return ans;
    }
};