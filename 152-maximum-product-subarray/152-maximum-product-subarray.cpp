class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int>dpmin(n,0);
        vector<int>dpmax(n,0);
        int ans=nums[0];
        dpmin[0]=nums[0],dpmax[0]=nums[0];
        for(int i=1;i<n;i++){
            dpmin[i]=min(dpmin[i-1]*nums[i],min(dpmax[i-1]*nums[i],nums[i]));
            dpmax[i]=max(dpmin[i-1]*nums[i],max(dpmax[i-1]*nums[i],nums[i]));
            ans=max(ans,dpmax[i]);
        }
        return ans;
    }
};