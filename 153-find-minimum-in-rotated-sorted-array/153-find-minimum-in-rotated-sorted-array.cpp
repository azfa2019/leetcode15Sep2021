class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r){
            int mid=(l+r)>>1;
            if(nums[mid]>nums[r]) l=mid+1;
            else r=mid;
        }
        return nums[l];
    }
};
// 3,4,5,1,2
// 1 2 3 4 5
// 5 1 2 3 4