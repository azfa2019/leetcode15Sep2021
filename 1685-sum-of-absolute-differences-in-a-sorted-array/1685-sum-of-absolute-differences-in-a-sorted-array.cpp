class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int>s(n);
        s[0]=nums[0];
        for(int i=1;i<n;i++) s[i]=s[i-1]+nums[i];
        vector<int>res;
        res.push_back(s[n-1]-s[0]-(n-1)*nums[0]);
        for(int i=1;i<n-1;i++){
            int l=s[i-1],r=s[n-1]-s[i];
            int rnum=n-1-(i+1)+1;
            int lnum=i-1+1;
            int diff=rnum-lnum;
            if(diff>0) res.push_back(r-l-diff*nums[i]);
            else res.push_back(r-l-diff*nums[i]);
        }
        
        res.push_back(-s[n-2]+(n-1)*nums[n-1]);
        return res;
    }
};