class Solution {
    vector<int>nums;
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        this->nums=nums;
        return helper(0,n-1);
    }
    int helper(int l, int r){
        if(l==r) return nums[l];
        if(l>r) return 0;
        int mid=l+r>>1;
        int lsum=helper(l,mid);
        int rsum=helper(mid+1,r);
        int lsumtmp=nums[mid],lsumMax=nums[mid];
        for(int i=mid-1;i>=l;i--){
            lsumtmp+=nums[i];
            lsumMax=max(lsumMax,lsumtmp);
        }
        int rsumtmp=nums[mid+1],rsumMax=nums[mid+1];
        for(int i=mid+2;i<=r;i++){
            rsumtmp+=nums[i];
            rsumMax=max(rsumMax,rsumtmp);
        }
        int xsum=lsumMax+rsumMax;
        return max(max(lsum,rsum),xsum);
    }
};