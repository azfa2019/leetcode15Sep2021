class Solution {
  public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int>map0;
    stack<int>stack0;
    int n=nums2.size();
    for(int i=n-1;i>=0;i--){
      while(!stack0.empty() && nums2[i]>stack0.top()) stack0.pop();
      map0[nums2[i]]=stack0.empty()?-1:stack0.top();
      stack0.push(nums2[i]);
    }
    for(int i=0;i<nums1.size();i++)
      nums1[i]=map0[nums1[i]];
    return nums1;
  }
};