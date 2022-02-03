class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int>cnt;
        for(int c:nums3)
            for(int d:nums4)
                cnt[c+d]++;
        int res=0;
        for(int a:nums1)
            for(int b:nums2)
                res+=cnt[-a-b];
        return res;
    }
};
