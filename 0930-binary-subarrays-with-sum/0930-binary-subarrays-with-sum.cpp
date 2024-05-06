class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>hash;
        hash[0]=1;
        int presum=0,cnt=0;
        for(int x:nums){
            presum+=x;
            if(hash.count(presum-goal)) cnt+=hash[presum-goal];
            hash[presum]++;
        }
        return cnt;
    }
};