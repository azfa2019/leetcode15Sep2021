class Solution {
public:
    bool check(int l,int r,vector<int>&nums){
        unordered_set<int>hash;
        int n=r-l+1;
        int mn=1e9,mx=-1e9;
        for(int i=l;i<=r;i++){
            hash.insert(nums[i]);
            mn=min(mn,nums[i]);
            mx=max(mx,nums[i]);
        }
        if((mx-mn)%(n-1)) return false;
        int d=(mx-mn)/(n-1);
        for(int i=1;i<n;i++)
            if(!hash.count(mn+(i-1)*d)) return false;
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans;
        for(int i=0;i<l.size();i++)
            ans.push_back(check(l[i],r[i],nums));
        return ans;
    }
};