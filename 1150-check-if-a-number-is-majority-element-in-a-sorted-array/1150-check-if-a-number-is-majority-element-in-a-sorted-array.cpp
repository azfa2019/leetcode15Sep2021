class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r){
            int mid=(l+r)>>1;
            if(nums[mid]>=target) r=mid;
            else l=mid+1;
        }
        if(nums[l]!=target) return false;
        int lb=l;
        l=0,r=n-1;
        while(l<r){
            int mid=(l+r+1)>>1;
            if(nums[mid]<=target) l=mid;
            else r=mid-1;
        }
        return (r-lb+1)>n/2;
    }
};