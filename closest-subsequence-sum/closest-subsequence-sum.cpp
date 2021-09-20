class Solution {
  public:
  int minAbsDifference(vector<int>& nums, int goal) {
    int m=nums.size()/2;
    vector<int>nums1(nums.begin(),nums.begin()+m);
    vector<int>nums2(nums.begin()+m,nums.end());
    vector<int>a=getSubsetSums(nums1);
    vector<int>b=getSubsetSums(nums2);
    int ans=INT_MAX;
    binarySearch(a,b,goal,ans);
    return ans;
  }
  vector<int>getSubsetSums(vector<int>&nums){
    vector<int>sums{0};
    for(int x:nums){
      vector<int>tmp;
      int i=0,j=0,n=sums.size();
      while(i<n && j<n){
        if(sums[i]+x<sums[j]) tmp.push_back(sums[i]+x),i++;
        else tmp.push_back(sums[j]),j++;
      }
      while(i<n) tmp.push_back(sums[i]+x),i++;
      while(j<n) tmp.push_back(sums[j]),j++;
      sums=tmp;
    }
    return sums;
  }
  void binarySearch(vector<int>&a,vector<int>&b,int goal,int& ans){
    for(auto x:a){
      auto iter=lower_bound(b.begin(),b.end(),goal-x);
      if(iter!=b.end()) ans=min(ans,abs(goal-x-*iter));
      if(iter!=b.begin()) ans=min(ans,abs(goal-x-*prev(iter)));
    }
  }
};