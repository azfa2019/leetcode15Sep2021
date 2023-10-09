class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=lowerbound(nums,target);
        if(l==nums.size() || nums[l]!=target) return {-1,-1};
        int r=lowerbound(nums,target+1)-1;
        return {l,r};
    }
    int lowerbound(vector<int>& nums,int x){
        int l=0,r=nums.size();
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]>=x) r=mid;
            else l=mid+1;
        }
        return l;
    }
};