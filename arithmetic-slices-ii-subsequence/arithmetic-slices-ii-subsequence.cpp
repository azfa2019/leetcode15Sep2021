class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
      int n=nums.size();
      vector<unordered_map<long,int>>dp(n);
      //dp[i][diff]: # of arithmetic subseq of size>=2 ending with i, with a difference of diff
      // 1 3 5 7 9
      // 5 7 & 9 forming a new subseq
      int res=0;
      for(long i=0;i<n;i++){
        for(int j=0;j<i;j++){
          long diff=(long)nums[i]-(long)nums[j];
          dp[i][diff]+=dp[j][diff]+1;
          res+=dp[j][diff];
        }
      }
      return res;
    }
};