class Solution {
    public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>stck;
        int n=nums2.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            while(!stck.empty() && nums2[i]>=stck.top()) {
                mp[stck.top()]=nums2[i];
                stck.pop();
            }
            stck.push(nums2[i]);
        }
        vector<int>ans;
        for(int num:nums1){
            if(mp.find(num)==mp.end()) ans.push_back(-1);
            else ans.push_back(mp[num]);
        }
        return ans;
    }
};
// 4 1 2
