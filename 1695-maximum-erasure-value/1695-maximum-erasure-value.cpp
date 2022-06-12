class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>s(n+1);
        s[0]=0;
        for(int i=0;i<n;i++) s[i+1]=s[i]+nums[i];
        //for(int i:s) cout<<i<<" ";
        //cout<<endl;
        unordered_map<int,int>fr;
        int ans=0;
        for(int l=0,r=0;r<n;r++){
            fr[nums[r]]++;
            while(fr[nums[r]]>1) fr[nums[l]]--,l++;
            ans=max(ans,s[r+1]-s[l]);
        }
        return ans;
    }
};