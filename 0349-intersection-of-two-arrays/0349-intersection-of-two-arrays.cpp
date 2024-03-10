class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>hash(1001),hash2(1001);
        for(int num:nums1){
            hash[num]=1;
        }
        for(int num:nums2){
            if(hash[num]) hash2[num]=1;
        }
        vector<int>ans;
        for(int i=0;i<=1000;i++)
            if(hash2[i]) ans.push_back(i);
        return ans;
    }
};