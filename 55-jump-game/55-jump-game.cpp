class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int far=0;
        for(int i=0;i<n;i++){
            if(far<i) return false;
            far=max(far,nums[i]+i);
        }
        return far>=n-1;
    }
};