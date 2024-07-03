class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=3) return 0;
        sort(nums.begin(),nums.end());
        int l1=nums[0],l2=nums[1],l3=nums[2],l4=nums[3];
        int r1=nums[n-1],r2=nums[n-2],r3=nums[n-3],r4=nums[n-4];
        int a=r4-l1,b=r3-l2,c=r2-l3,d=r1-l4;
        return min(min(a,b),min(c,d));
    }
};