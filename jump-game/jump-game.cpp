class Solution {
  public:
  bool canJump(vector<int>& nums) {
    int n=nums.size();
    int pos=n-1;
    for(int i=n-1;i>=0;i--){
      if(i+nums[i]>=pos) pos=i;
    }
    return pos==0;
  }
};
// 3 2 1 0 4
//         i pos=4
//       i   pos=4
// 2 3 1 1 4
//         i pos=4
//       i   pos=3
//     i     pos=2
//   i       pos=1
// i         pos=0
