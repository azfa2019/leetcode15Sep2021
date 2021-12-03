class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        int minPTmp,maxPTmp;
        int minP=1,maxP=1;
        for(int i=0;i<n;i++){
            minPTmp=minP;
            maxPTmp=maxP;
            minP=min(min(minPTmp*nums[i],maxPTmp*nums[i]),nums[i]);
            maxP=max(max(minPTmp*nums[i],maxPTmp*nums[i]),nums[i]);
            ans=max(ans,maxP);
        }
        return ans;
    }
};