class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp{{0,1}};
        int sum=0;
        int cnt=0;
        for(int num:nums){
            sum+=num;
            if(mp.find(sum-k)!=mp.end()) cnt+=mp[sum-k];
            mp[sum]++;
        }
        return cnt;
    }
};