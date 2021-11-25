class Solution {
  public:
  int maxSubArray(vector<int>& nums) {
    int n=nums.size();
    return divide(nums,0,n-1);
  }
  int divide(vector<int>& nums,int left,int right){
    if(left==right) return nums[left];
    int mid=left+(right-left)/2;
    int lsum=divide(nums,left,mid);
    int rsum=divide(nums,mid+1,right);
    
    int lx=0,lxmax=nums[mid];
    for(int i=mid;i>=left;i--) {
      lx+=nums[i];
      lxmax=max(lxmax,lx);
    }
    int rx=0,rxmax=nums[mid+1];
    for(int i=mid+1;i<=right;i++) {
      rx+=nums[i];
      rxmax=max(rxmax,rx);
    }
    int xmax=lxmax+rxmax;
    return max(lsum,max(rsum,xmax));
  }
};