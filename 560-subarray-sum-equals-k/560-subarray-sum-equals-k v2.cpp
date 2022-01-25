class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>s(n+1);
        int res=0;
        for(int i=1;i<=n;i++) s[i]=s[i-1]+nums[i-1];
        unordered_map<int,int>hash{{0,1}};
        for(int i=1;i<=n;i++){
            res+=hash[s[i]-k];
            hash[s[i]]++;
        }
        return res;
    }
};
