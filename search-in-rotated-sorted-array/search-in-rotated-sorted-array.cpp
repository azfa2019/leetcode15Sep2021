class Solution {
  public:
  int search(vector<int>& nums, int target) {
    int n=nums.size();
    int left=0,right=n-1;
    while(left<right){
      int mid=left+(right-left)/2;
      if(nums[mid]>nums[left]){ //left is monotonic
        if(nums[mid]>=target&&target>=nums[left]) right=mid;
        else left=mid+1;
      }else{//right side is monotonic
        if(nums[mid+1]<=target&&target<=nums[right]) left=mid+1;
        else right=mid;
      }
    }
    cout<<left<<endl;
    return nums[left]==target?left:-1;
  }
};

//4,5,6,7,0,1,2, m>right && nums[mid]>target, right=mid-1;
// else left=mid
// compare: target & left/right, or mid and left/right?
// if target>nums[left] && mid>target, right=mid-1
//else left=mid
//6,7,0,1,2,4,5, 7 is target, mid=1
//compare target and nums[left] no go
//mid > left: left monotonic, 