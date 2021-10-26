class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
      //up[i], down[i]: ending with nums[i]
      // 1 7 4   9 2 5
      //.    i-1 i
      int n=nums.size();
      int up=1,down=1;
      for(int i=1;i<n;i++){
        if(nums[i]>nums[i-1]) up=down+1;
        else if(nums[i]<nums[i-1]) down=up+1;
      }
      return max(up,down);
    }
};