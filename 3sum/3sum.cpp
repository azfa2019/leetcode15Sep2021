//deal with duplicates: i, left and right
// if() continue or while() left++
class Solution {
  public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int n=nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    for(int i=0;i<n-2;i++){
      if(i>0 && nums[i]==nums[i-1]) continue;
      int left=i+1,right=n-1;
      int target=0-nums[i];
      while(left<right){
        if(nums[left]+nums[right]<target) left++;
        else if(nums[left]+nums[right]>target) right--;
        else {
          ans.push_back({nums[i],nums[left],nums[right]});
          left++;
          right--;
          while(left<right && nums[left]==nums[left-1]) left++;
          while(left<right && nums[right]==nums[right+1]) right--;
        }
      }
    }
    return ans;
  }
};
//class Solution {
//    public:
//    vector<vector<int>> threeSum(vector<int>& nums) {//140
//        int n=nums.size();
//        if(n<3) return {};
//        sort(nums.begin(),nums.end());
//        vector<vector<int>> ans;
//        for(int i=0;i<n-2;i++){
//            if(i>0 && nums[i]==nums[i-1]) continue;
//            findPair(nums,i,ans);
//        }
//        return ans;
//    }
//    void findPair(vector<int>&nums,int first,vector<vector<int>>&ans){
//        int left=first+1,right=nums.size()-1;
//        while(left<right){
//            int sum=nums[first]+nums[left]+nums[right];
//            if(sum==0) {
//                ans.push_back({nums[first],nums[left],nums[right]});
//                left++;
//                right--;
//                while(left<right && nums[left]==nums[left-1]) left++;
//                while(left<right && nums[right]==nums[right+1]) right--;
//            } else if(sum<0) left++;
//            else right--;
//        }
//    }
//};

//deal with duplicates: i, left and right
// if() continue or while() left++
//class Solution {
//  public:
//  vector<vector<int>> threeSum(vector<int>& nums) {//140
//    int n=nums.size();
//    vector<vector<int>>res;
//    sort(nums.begin(),nums.end());
//    for(int i=0;i<n-2;i++){
//      while(i>0 && i<n && nums[i]==nums[i-1]) i++;
//      int left=i+1,right=n-1;
//      while(left<right){
//        int sum=nums[i]+nums[left]+nums[right];
//        if(sum==0) {
//          res.push_back({nums[i],nums[left],nums[right]});
//          left++;
//          right--;
//          while(left<right && nums[left]==nums[left-1]) left++;
//          while(left<right && nums[right]==nums[right+1]) right--;
//        } else if(sum<0) left++;
//        else if(sum>0) right--;
//      }
//    }
//    return res;
//  }
//};
//