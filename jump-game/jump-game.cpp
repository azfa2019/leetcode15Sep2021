class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int pos=n-1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]+i>=pos) pos=i;
        }
        return pos==0;
    }
};