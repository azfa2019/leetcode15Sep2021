class Solution {
    public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0,right=n-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]>=nums[left]){
                if(nums[mid]>=target && target>=nums[left])
                    right=mid;
                else 
                    left=mid+1;
            }else{
                if(nums[mid+1]<=target && target<=nums[right])
                    left=mid+1;
                else 
                    right=mid;
            }
        }
        return nums[left]==target?left:-1;
    }
};
//[4,5,6,7,0,1,2] t=5, t=0
//       m
//0,1,2,4,5,6,7 t=2, t=5
//      m
//7,0,1,2,4,5,6, t=1
//      m