class Solution {
public:
    int lowbit(int x) {
        return x&-x;
    }
    int minOperations(vector<int>& nums, int k) {
        for(int& x:nums) k^=x;
        int cnt=0;
        while(k) cnt++,k-=lowbit(k);
        return cnt;
    }
};