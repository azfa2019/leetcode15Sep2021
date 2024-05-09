class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>hash;
        hash[0]=1;
        int cnt=0,presum=0;
        for(int x:nums){
            presum+=x;
            if(hash.count(presum-k)) cnt+=hash[presum-k];
            hash[presum]++;
        }
        return cnt;
    }
};