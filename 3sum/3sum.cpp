class Solution {
  public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int n=nums.size();
    vector<vector<int>>ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n-2;i++){
      while(i>0 && i<n && nums[i]==nums[i-1]) i++;
      findpair(nums,i,ans);
    }
    return ans;
  }
  void findpair(vector<int>& nums,int i,vector<vector<int>>&ans){
    int left=i+1,right=nums.size()-1;
    while(left<right){
      int sum=nums[left]+nums[right]+nums[i];
      if(sum==0){
        ans.push_back({nums[i],nums[left],nums[right]});
        left++;
        right--;
        while(left<right && nums[left]==nums[left-1]) left++;
        while(left<right && nums[right]==nums[right+1]) right--;
      }else if(sum<0) left++;
      else right--;
    }
  }
};