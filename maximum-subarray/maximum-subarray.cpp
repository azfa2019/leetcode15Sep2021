class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      return divide(nums,0,nums.size()-1);
    }
  int divide(vector<int>& nums,int start,int end){
    if(start==end) return nums[start];
    int mid=(start+end)/2;
    int lMax=divide(nums,start,mid);
    int rMax=divide(nums,mid+1,end);
    
    int lxMax=nums[mid];
    int lsum=0;
    for(int i=mid;i>=start;i--){
      lsum+=nums[i];
      lxMax=max(lxMax,lsum);
    }
    int rxMax=nums[mid+1];
    int rsum=0;
    for(int i=mid+1;i<=end;i++){
      rsum+=nums[i];
      rxMax=max(rxMax,rsum);
    }
    int xMax=lxMax+rxMax;
    return max({xMax,lMax,rMax});
  }
};