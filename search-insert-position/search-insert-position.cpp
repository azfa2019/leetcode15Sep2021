class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        if(target<nums[0]) return 0;
        if(target>nums[n-1]) return n;
        int left=0,right=n-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]<target) left=mid+1;
            else right=mid;
        }
        return left;
    }
};
// 1 3 5 6 t=5
//   m
// 1 3 5 6 t=3
//   m
// 1 3 5 6 t=2
//   m