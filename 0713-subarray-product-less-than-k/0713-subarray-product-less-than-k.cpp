class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<1) return 0; 
        int n=nums.size();
        int l=0,prod=1,res=0;
        for(int r=0;r<n;r++){
            prod*=nums[r];
            while(l<=r && prod>=k) prod/=nums[l++];
            res+=r-l+1;
        }
        return res;
    }
};