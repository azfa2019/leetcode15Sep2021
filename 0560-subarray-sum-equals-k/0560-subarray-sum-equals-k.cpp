class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        //vector<int>presum(n+1);
        int presum=0;
        unordered_map<int,int>hash;
        hash[0]=1;
        int cnt=0;
        for(int num:nums){
            presum+=num;
            if(hash.count(presum-k)) cnt+=hash[presum-k];
            hash[presum]++;
        }
        return cnt;
    }
};