class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        nums.push_back(1e5);
        int l=0,r=nums.size()-1;
        while(l<r){
            int mid=(l+r)>>1;
            if(nums[mid]<target) l=mid+1;
            else r=mid;
        }
        return l;
    }
};