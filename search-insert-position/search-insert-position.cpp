class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        if(target<nums[0]) return 0;
        if(target>nums[n-1]) return n;
        int left=0,right=n-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]>=target) right=mid;
            else left=mid+1;
        }
        return left;
    }
};

// 1  3 5 6 
//.   m t
// 1  3 5 6 t=2
//.   m 