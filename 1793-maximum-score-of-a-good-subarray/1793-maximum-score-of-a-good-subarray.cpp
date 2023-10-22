class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int l=k,r=k,n=nums.size(),res=0;
        while(true){
            while(r<n&&nums[r]>=nums[k]) r++;
            
            while(l>=0&&nums[l]>=nums[k]) l--;
            res=max(res,(r-l-1)*nums[k]);
            if(l<0&&r==n) break;
            if(l>=0&&r<n) nums[k]=max(nums[l],nums[r]);
            else if(l<0) nums[k]=nums[r];
            else nums[k]=nums[l];
        }
        return res;
    }
};