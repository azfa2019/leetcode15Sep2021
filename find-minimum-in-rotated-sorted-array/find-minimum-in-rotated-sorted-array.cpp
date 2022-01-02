class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int left=0,right=n-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]>nums[right]) left=mid+1;
            else right=mid;
        }
        return nums[left];
    }
};
// 3,4,5,1,2  mid>left, left=mid+1
//     m
// mid>right, left=mid+1
// 1 2 3 4 5 mid>left,right=mid-1
//     m
// mid<right, right=mid
// 5 1 2 3 4
//     m
// mid<right, right=mid