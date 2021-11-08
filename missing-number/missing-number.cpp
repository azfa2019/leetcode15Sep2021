class Solution {
  public:
  int missingNumber(vector<int>& nums) {
    int n=nums.size();
    int sum=0;
    for(int num:nums) sum+=num;
    return n*(n+1)/2-sum;
  }
//  void swap(vector<int>&nums,int i,int j){
//    int tmp=nums[i];
//    nums[i]=nums[j];
//    nums[j]=tmp;
//  }
};