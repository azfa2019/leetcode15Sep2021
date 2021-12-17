class Solution {
    public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>nums2(nums.begin(),nums.end());
        nums2.insert(nums2.end(),nums.begin(),nums.end());
        stack<int>stck;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<2*n;i++){
            while(!stck.empty() && nums2[stck.top()]<nums2[i]){
                mp[stck.top()]=i;
                stck.pop();
            }
            stck.push(i);
        }
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            if(mp.find(i)!=mp.end()) {
                ans[i]=nums2[mp[i]];
            }
        }
        return ans;
    }
};