class Solution {
public:
    int arraySign(vector<int>& nums) {
        //long long p=1;
        int cnt=0;
        for(int n:nums) {
            if(n==0) return 0;
            if(n<0) cnt++;
        }
        if(cnt&1) return -1;
        else return 1;
    }
};