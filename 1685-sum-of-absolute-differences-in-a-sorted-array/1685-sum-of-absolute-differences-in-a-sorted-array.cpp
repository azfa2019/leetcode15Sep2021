class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int>s(n+1);
        for(int i=0;i<n;i++) s[i+1]=s[i]+nums[i];
        vector<int>res(n);
        
        for(int i=0;i<n;i++){
            int l=i*nums[i]-s[i],r=s[n]-s[i+1]-(n-i-1)*nums[i];
            res[i]=l+r;
        }
        return res;
    }
};