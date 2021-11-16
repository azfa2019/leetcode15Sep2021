class Solution {
  public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int n=nums.size();
    unordered_map<int,int>map0;
    for(int i=0;i<n;i++){
      if(map0.find(target-nums[i])!=map0.end()) return {i,map0[target-nums[i]]};
      map0.insert({nums[i],i});
    }
    return {-1,-1};
  }
};
//    //method 1: brute force, O(n^2), O(1)
//class Solution {
//  public:
//  vector<int> twoSum(vector<int>& nums, int target) {
//    for(int i=0;i<nums.size();i++){
//      for(int j=i+1;j<nums.size();j++){
//        if(nums[i]+nums[j]==target) return {i,j};
//      }
//    }
//    return {};
//  }
//};
//method 2: hashmap, O(n), O(n)
//class Solution {
//  public:
//  vector<int> twoSum(vector<int>& nums, int target) {
//    unordered_map<int,int>map;
//    for(int i=0;i<nums.size();i++){
//      int potentialMatch=target-nums[i];
//      if(map.find(potentialMatch)!=map.end()) return {map[potentialMatch],i};
//      else map.insert({nums[i],i});
//    }
//    return {};
//  }
//};
//    //method 3: sort + 2 pointers, O(nlogn), O(1)
//    //tricky part: find the index of sorted numbers, use a for loop
//class Solution {
//  public:
//  vector<int> twoSum(vector<int>& nums, int target) {
//    auto sorted=nums;
//    sort(sorted.begin(),sorted.end());
//    int left=0,right=nums.size()-1;
//    while(left<right){
//      int sum=sorted[left]+sorted[right];
//      if(sum==target) break;
//      else if(sum<target) left++;
//      else if(sum>target) right--;
//    }
//    if(left>=right) return {};
//    int idx1=-1,idx2=-1;
//    for(int i=0;i<nums.size();i++){
//      if(nums[i]==sorted[left]||nums[i]==sorted[right]){
//        if(idx1==-1) idx1=i;
//        else idx2=i;
//      }
//    }
//    return {idx1,idx2};
//  }
//};