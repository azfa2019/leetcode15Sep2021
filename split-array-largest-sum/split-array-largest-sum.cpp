class Solution {
  int n;
public:
    int splitArray(vector<int>& nums, int m) {
      n=nums.size();
      long left=0,right=INT_MAX;
      while(left<right){
        long mid=left+(right-left)/2;
        if(check(nums,m,mid)) right=mid;
        else left=mid+1;
      }
      return left;
    }
  bool check(vector<int>&nums,int m,long val){
    int count=1;
    long total=0;
    for(int num:nums){
      if(num>val) return false;
      total+=num;
      if(total>val){
        total=num;//reset
        count++;
        if(count>m) return false;
      }
    }
    return count<=m;
  }
  bool check1(vector<int>&nums,int m,long val){
    int count=0;
    for(int i=0;i<n;i++){
      if(nums[i]>val) return false;
      int j=i;
      int sum=0;
      while(j<n && sum+nums[j]<=val){
        sum+=nums[j];
        j++;
      }
      count++;
      i=j-1;
    }
    return count<=m;
  }
};