class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>s(n+1);
        for(int i=1;i<=n;i++){
            int t=s[i-1]-s[max(i-k,0)]&1;
            nums[i-1]^=t;
            if(!nums[i-1]) {
                if(i>=n-k+2) return -1;
                s[i]++;
            }
            s[i]+=s[i-1];
        }
        return s[n];
    }
};