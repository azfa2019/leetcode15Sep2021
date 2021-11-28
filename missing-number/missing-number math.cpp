class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int n=nums.size();
      int sum=0;
      for(int num:nums) sum+=num;
      return (n+1)*n/2-sum;
    }
};
// 0 1   3
// 0 1   2
