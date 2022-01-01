class Solution {
    public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(int num:nums) st.insert(num);
        int n=nums.size();
        int ans=0;
        int i=0;
        for(int i=0;i<n;i++){
            if(st.find(nums[i]-1)!=st.end()) {
                continue;
            }
            int left=nums[i];
            int right=nums[i];
            while(st.find(right)!=st.end()) right++;
            int size=right-1-left+1;
            ans=max(ans,size);
        }
        return ans;
    }
};