class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int n=nums.size(),min_i=-1,max_i=-1,i0=-1;
        for(int i=0;i<n;i++){
            int x=nums[i];
            if(x==minK) min_i=i;
            if(x==maxK) max_i=i;
            if(x<minK||x>maxK) i0=i;
            ans+=max(min(min_i,max_i)-i0,0);
        }
        return ans;
    }
};