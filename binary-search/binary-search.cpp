class Solution {
  public:
  int search(vector<int>& nums, int target) {
      int n=nums.size();
      int l=0,r=n-1;
      while(l<r){
          int m=l+((r-l)>>1);
          if(target>nums[m]) l=m+1;
          else r=m;
      }
      return nums[l]==target?l:-1;
  }
};
//.     left. right. mid nums[mid]>target? 
//5 9   0.    1      1   9, no
//      1

//.     left. right. mid nums[mid]>target? 
//5 9   0.    1      0   5, no
//      0