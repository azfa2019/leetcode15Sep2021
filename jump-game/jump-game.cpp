class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int i=0,far=0;
        for(int i=0;i<n;i++){
            far=max(far,nums[i]+i);
            if(far>=n-1) return true;
            if(far<=i) return false;
        }
        //return far>=n-1?true;false;
        return false;
    }
};