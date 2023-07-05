class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size(),cnt=0;
        int len=0;
        for(int r=0,l=0;r<n;r++){
            cnt+=1-nums[r];
            while(l<n && cnt>1) cnt-=1-nums[l++];
            len=max(len,r-l);
        }
        return len;
    }
};