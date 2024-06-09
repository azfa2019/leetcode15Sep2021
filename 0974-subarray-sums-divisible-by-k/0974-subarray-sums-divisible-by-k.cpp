class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size(),ans=0,sum=0;
        unordered_map<int,int>hash;
        hash[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int t=(sum%k+k)%k;
            if(hash.count(t)) ans+=hash[t];
            hash[t]++;
        }
        return ans;
    }
};