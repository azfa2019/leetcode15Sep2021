class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int left=0,right=n-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]<nums[right]) right=mid;
            else if(nums[mid]>nums[right]) left=mid+1;
            else right--;
        }
        return nums[left];
    }
};
//0,1,4,4,5,6,7
//.     m
//0,1,4,4,0
//.   m
