class Solution {
  public:
  bool canJump(vector<int>& nums) {
    int n=nums.size();
    if(n==1) return true;
    int maxReach=nums[0];
    for(int i=1;i<n;i++){
      if(i>maxReach) return false;
      maxReach=max(maxReach,i+nums[i]);
      if(i+nums[i]>=n-1) return true;
      //2 1 0 3 1
    }
    return false;
  }
};