class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int m=nums[n/2];
        
        if(n&1) m=nums[(n-1)/2];
        int ans=0;
        for(int i:nums) ans+=abs(m-i);
        return ans;
    }
};