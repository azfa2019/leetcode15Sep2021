class Solution {
public:
    int rev(int x){
        int y=0;
        while(x>0){
            y=y*10+x%10;
            x/=10;
        }
        return y;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int>cnt;
        int res=0;
        const int mod=1e9+7;
        for(int x:nums){
            int y=x-rev(x);
            res=(res+cnt[y]++)%mod;
        }
        return res;
    }
};