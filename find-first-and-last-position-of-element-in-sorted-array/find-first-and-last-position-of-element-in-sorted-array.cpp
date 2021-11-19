class Solution {
  public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int n=nums.size();
    if(n==0) return {-1,-1};
    if(target<nums[0]||target>nums[n-1]) return {-1,-1};
    int left=0,right=n-1;
    while(left<right){
      int mid=left+(right-left)/2;
      if(nums[mid]>=target) right=mid;
      else left=mid+1;
    }
    int l=nums[left]==target?left:-1;
    if(l==-1) return {-1,-1};
    
    left=0,right=n-1;
    while(left<right){
      int mid=left+(right-left+1)/2;
      if(nums[mid]<=target) left=mid;
      else right=mid-1;
    }
    int r=left;
    return {l,r};
  }
};
//class Solution {
//public:
//    vector<int> searchRange(vector<int>& nums, int target) {//30
//        //idx=mid, then expand: start=mid+1, or end=mid-1;
//        vector<int>res{-1,-1};
//        res[0]=findRange(nums,target,false);
//        if(res[0]!=-1) res[1]=findRange(nums,target,true);
//        return res;
//    }
//    int findRange(vector<int>& nums,int target,bool findMax){
//        int start=0,end=nums.size()-1;
//        int idx=-1;
//        while(start<=end){
//            int mid=start+(end-start)/2;
//            if(target<nums[mid]) end=mid-1;
//            else if(target>nums[mid]) start=mid+1;
//            else {
//                idx=mid;
//                if(findMax) start=mid+1;
//                else end=mid-1;
//            }
//        }
//        return idx;
//    }
//};