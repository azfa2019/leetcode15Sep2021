class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int n=nums.size();
        vector<int>dpmin(n,0);
        vector<int>dpmax(n,0);
        dpmin[0]=nums[0];
        dpmax[0]=nums[0];

        for(int i=1;i<n;i++){
            dpmax[i]=max(dpmin[i-1]*nums[i],max(nums[i],dpmax[i-1]*nums[i]));
            dpmin[i]=min(dpmin[i-1]*nums[i],min(nums[i],dpmax[i-1]*nums[i]));
            ans=max(ans,dpmax[i]);
        }
        return ans;
    }
};