class Solution {
  public:
  int singleNonDuplicate(vector<int>& nums) {
    int n=nums.size();
    int left=0,right=n-1;
    while(left<right){
      int mid=left+(right-left)/2;
      if(nums[mid]==nums[mid-1]) {
        if((mid-left+1)%2==0) left=mid+1;
        else right=mid-2;
      }else if(nums[mid]==nums[mid+1]){
        if((mid-left+1)%2==0) right=mid-1;
        else left=mid+2;
      }else return nums[mid];
    }
    return nums[left];
  }
};
//1,1,2,3,3,4,4
//.     m 
//1,1,2,2,3,3,4,4,5,8,8
//.         m
//3,3,7,7,10,11,11
//.     m