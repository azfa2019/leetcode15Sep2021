class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int>q(2,INT_MAX);
        for(auto x:nums){
            int k=2;
            while(k>0 && q[k-1]>=x) k--;
            if(k==2) return true;
            q[k]=x;
        }
        return false;
    }
};