class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>hash;
        hash[0]=-1;
        int n=nums.size(),s=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
            if(hash.count(s%k)) {
                if(i-hash[s%k]>=2) return true;
                continue;
            }
            hash[s%k]=i;
        }
        return false;
    }
};