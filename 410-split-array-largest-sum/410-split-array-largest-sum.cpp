class Solution {
    public:
    bool check(vector<int>&nums,int m,int mid){
        int sum=0,cnt=0;
        for(auto x:nums){
            if(x>mid) return false;
            if(sum+x>mid){
                sum=x;
                cnt++;
            }else sum+=x;
        }
        if(sum) cnt++;
        return cnt<=m;
    }
    int splitArray(vector<int>& nums, int m) {
        int l=0,r=INT_MAX;
        while(l<r){
            int mid=(long long) l+r>>1;
            if(check(nums,m,mid)) r=mid;
            else l=mid+1;
        }
        return l;
    }
};