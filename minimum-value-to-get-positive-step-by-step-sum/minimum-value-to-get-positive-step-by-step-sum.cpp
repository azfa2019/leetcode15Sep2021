class Solution {
public:
    int minStartValue(vector<int>& nums) {
      int minSum=INT_MAX;
      int sum=0;
      for(int num:nums){
        sum+=num;
        minSum=min(minSum,sum);
      }
      cout<<minSum<<endl;
      return (1-minSum)<=0?1:(1-minSum);
    }
};