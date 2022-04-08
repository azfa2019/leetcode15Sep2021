class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
     sort(nums1.begin(),nums1.end());
        int n=nums1.size();
        vector<int>count(101);
        for(int num:nums2) count[num]++;
        int cur=100;
        int res=0;
        for(int i=0;i<n;i++){
            while(count[cur]==0) cur--;
            res+=nums1[i]*cur;
            count[cur]--;
        }
        
        return res;
    }
};