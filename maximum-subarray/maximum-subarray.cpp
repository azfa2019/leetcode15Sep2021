class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return divide(nums,0,nums.size()-1);
    }
    int divide(vector<int>& nums,int l,int r){
        if(l==r) return nums[l];
        int mid=l+(r-l)/2;
        int ls=divide(nums,l,mid);
        int rs=divide(nums,mid+1,r);
        int lsum=0,lsumMax=INT_MIN;
        for(int i=mid;i>=l;i--){
            lsum+=nums[i];
            lsumMax=max(lsumMax,lsum);
        }
        int rsum=0,rsumMax=INT_MIN;
        for(int i=mid+1;i<=r;i++){
            rsum+=nums[i];
            rsumMax=max(rsumMax,rsum);
        }
        int xsum=lsumMax+rsumMax;
        return max(max(ls,rs),xsum);
    }
};