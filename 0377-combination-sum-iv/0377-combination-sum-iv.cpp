class Solution {
public:
    int combinationSum4(vector<int>& nums, int m) {
        int n=nums.size();
        vector<long long>f(m+1);
        f[0]=1;
        for(int j=0;j<=m;j++)
            for(auto v:nums)
                if(j>=v) f[j]=(f[j]+f[j-v])%INT_MAX;
        return f[m];
    }
};