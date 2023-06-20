class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>s(n+1);
        vector<int>res;
        if(n<2*k+1) {
            for(int i=0;i<n;i++) res.push_back(-1);
            return res;
        }
        for(int i=1;i<=n;i++) s[i]=s[i-1]+nums[i-1];
        
        for(int i=0;i<k;i++) res.push_back(-1);
        for(int i=k;i<n-k;i++) res.push_back((s[i+k+1]-s[i-k])/(k*2+1));
        for(int i=n-k;i<n;i++) res.push_back(-1);
        return res;
    }
};