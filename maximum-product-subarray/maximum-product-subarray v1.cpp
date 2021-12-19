class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int minP=1,maxP=1;
        int minPTmp,maxPTmp;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            minPTmp=minP,maxPTmp=maxP;
            minP=min(min(minPTmp*nums[i],maxPTmp*nums[i]),nums[i]);
            maxP=max(max(minPTmp*nums[i],maxPTmp*nums[i]),nums[i]);
            ans=max(ans,maxP);
        }
        return ans;
    }
};
