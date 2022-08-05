class Solution {
public:
    int combinationSum4(vector<int>& nums, int m) {
        vector<unsigned> f(m+1);
        f[0]=1;
        for(int i=1;i<=m;i++)
            for(auto j:nums)
                if(i>=j) f[i]+=f[i-j];
        return f[m];
    }
};