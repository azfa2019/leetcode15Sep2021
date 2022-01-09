class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0) return {-1,-1};
        int left=0,right=n-1;
        while(left<right){
            int mid=left+right>>1;
            if(nums[mid]<target) left=mid+1;
            else right=mid;
        }
        if(nums[left]!=target) return {-1,-1};
        int l=left;
        left=0,right=n-1;
        while(left<right){
            int mid=left+right+1>>1;
            if(nums[mid]>target) right=mid-1;
            else left=mid;
        }
        return {l,left};
    }
};
// 5,7,7,7,8,8,10 t=8
// ==8, right=mid
// <8, left=mid+1
// >8, right=mid
// 
// 5,7,7,7,8,8,10 t=8
//       m
// right boundary
// <8, left=mid
// >8, right=mid-1
// ==8, left=mid