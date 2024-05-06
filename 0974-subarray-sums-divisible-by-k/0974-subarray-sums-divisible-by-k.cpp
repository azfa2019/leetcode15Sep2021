class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt=0,presum=0;
        unordered_map<int,int>hash;
        hash[0]=1;
        for(int x:nums){
            presum+=x;
            int key=(presum%k+k)%k;
            if(hash.count(key)) cnt+=hash[key];
            hash[key]++;
        }
        return cnt;
    }
};