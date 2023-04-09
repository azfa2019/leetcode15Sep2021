class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        unordered_map<int,int>hash;
        for(int i=0;i<n;i++) hash[nums2[i]]=i;
        vector<int>ans;
        for(int n:nums1) ans.push_back(hash[n]);
        return ans;
    }
};