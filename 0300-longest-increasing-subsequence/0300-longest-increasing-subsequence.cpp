class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>f(n,1);
        int res=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]) f[i]=max(f[i],1+f[j]);
            }
            res=max(res,f[i]);
        }
        return res;
    }
};