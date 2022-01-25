class Solution {
public:
    bool check(vector<int>&nums,int mid,int m){
        int sum=0,cnt=0;
        for(int num:nums){
            if(num>mid) return false;
            if(sum+num>mid) {
                sum=num;
                cnt++;
            }else sum+=num;
        }
        if(sum) cnt++;
        return cnt<=m;
    }
    int splitArray(vector<int>& nums, int m) {
        int l=0,r=INT_MAX;
        while(l<r){
            int mid=(long long)l+r>>1;
            if(check(nums,mid,m)) r=mid;
            else l=mid+1;
        }
        return l;
    }
};