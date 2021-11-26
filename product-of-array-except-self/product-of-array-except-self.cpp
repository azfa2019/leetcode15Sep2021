class Solution {
  public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n=nums.size();
    vector<int>ans(n);
    int tmp=1;
    for(int i=1;i<n;i++){
      tmp*=nums[i-1];
      ans[i]=tmp;
    }
    tmp=1;
    ans[0]=1;
    for(int i=n-2;i>=0;i--){
      tmp*=nums[i+1];
      ans[i]*=tmp;
    }
    return ans;
  }
};
// 1 2   3 4
//   i   i tmp
// 1 2    3 4
//.  i-1  i
//.  b
//ans[1]=1*1=1
//ans[2]=1*2=2
//ans[3]=nums[2]*ans[2]=3*2=6