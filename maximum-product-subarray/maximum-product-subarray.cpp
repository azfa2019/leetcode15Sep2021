class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int n=nums.size();
      int minp=1,maxp=1,ans=nums[0];
      for(int i=0;i<n;i++){
        int minpTmp=minp,maxpTmp=maxp;
        minp=min({minpTmp*nums[i],nums[i],maxpTmp*nums[i]});
        maxp=max({minpTmp*nums[i],nums[i],maxpTmp*nums[i]});
        ans=max(ans,maxp);
      }
      return ans;
    }
};
// 2 3 -2 4
//i minp maxp num
//0 2.   2.   2
//1 3     6.   3
//2 -12   -2.  -2 
//3 -48   4      4