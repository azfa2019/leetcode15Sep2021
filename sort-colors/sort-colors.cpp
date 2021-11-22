class Solution {
  public:
  void sortColors(vector<int>& nums) {
    // 2 0 2 1 1 0
    // 0 0 2 1 1 2
    //left: 0 pointer
    //i: 1 pointer
    //right: 2 pointer

    int n=nums.size();
    int left=0,right=n-1,i=0;
    while(i<=right){
      if(nums[i]==1) i++;
      else if(nums[i]==0) {
        swap(nums[i],nums[left]);
        i++,left++;
      }
      else {
        swap(nums[i],nums[right]);
        right--;
      }
    }
  }
};
// 2 0 2 1 1 0
//     i
// 0 0 2 1 1 2
//.    l   r
//     i
// 0 0 1 1 2 2
//.    l r