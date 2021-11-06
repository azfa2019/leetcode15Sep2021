class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n1n2=0;
      for(int num:nums) n1n2^=num;
      int right1=1;
      while((n1n2&right1)==0) right1=(right1<<1);
      int n1=0,n2=0;
      for(int num:nums){
        if((right1&num)==0) n1^=num;
        else n2^=num;
      }
      return {n1,n2};
    }
};