class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxCur=1,minCur=1;
        int ans=nums[0];
        for(int num:nums){
            int maxTmp=maxCur,minTmp=minCur;
            maxCur=max(maxTmp*num,max(minTmp*num,num));
            minCur=min(maxTmp*num,min(minTmp*num,num));
            ans=max(ans,maxCur);
        }
        return ans;
    }
};