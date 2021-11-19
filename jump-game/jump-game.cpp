class Solution {
  public:
  bool canJump(vector<int>& nums) {
    int maxReach=nums[0];
    for(int i=0;i<nums.size();i++){
      if(maxReach<i) return false;
      int curReach=nums[i]+i;
      maxReach=max(maxReach,curReach);
    }
    return true;
  }
};
// 3 3 1 0 4