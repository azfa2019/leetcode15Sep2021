class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        int cur=100;
        int n=nums1.size();
        vector<int>freq(101);
        for(int x:nums2) freq[x]++;
        int res=0;
        for(int i=0;i<n;i++){
            while(freq[cur]==0) cur--;
            res+=cur*nums1[i];
            freq[cur]--;
        }
        return res;
    }
};
