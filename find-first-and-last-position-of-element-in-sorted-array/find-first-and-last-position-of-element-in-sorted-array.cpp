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
        int l=left;
        left=0,right=n-1;
        while(left<right){
            int mid=left+(right-left+1)/2;
            if(nums[mid]<=target) left=mid;
            else right=mid-1;
        }
        return {l,left};
    }
};

// 5,7,7,8,8,10, t=8
//     m
// 5,7,7,8,8,10, t=6
//     m
// 5,7,7,8,8,10, t=7
//     m