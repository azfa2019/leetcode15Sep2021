class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size(),sum=0,res=0;
        unordered_map<int,int>cnt;
        cnt[0]=1;
        for(int x:nums){
            if(x%2) sum++;
            res+=cnt[sum-k];
            cnt[sum]++;
        }
        return res;
    }
};