class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0) return {-1,-1};
        int left=0,right=n-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]<target) left=mid+1;
            else right=mid;
        }
        if(nums[left]!=target) return {-1,-1};
        int left0=left;
        left=0,right=n-1;
        while(left<right){
            int mid=left+(right-left+1)/2;
            if(nums[mid]<=target) left=mid;
            else right=mid-1;
        }
        return {left0,left};
    }
};
//5,5,5,8,8,10 nums[mid]=target, left=mid
//. t m 
//5,5,6,8,8,10 nums[mid]>target, right=mid-1
//. t m 
//5,5,6,8,8,10 nums[mid]<target, left=mid
//.   m t 
//5,5,7,8,8,10
//. t m 
//5,7,7,8,8,10
//.   m t
//5,7,8,8,8,10
//.   m t
//5,7,8,8,8,10
//. t m