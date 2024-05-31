class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long sum=0;
        for(auto&x:nums) sum^=x;
        int lowbit=sum&(-sum);
        vector<int>ans(2);
        for(auto &x:nums){
            ans[(x&lowbit)==0]^=x;
        }
        return ans;
    }
};