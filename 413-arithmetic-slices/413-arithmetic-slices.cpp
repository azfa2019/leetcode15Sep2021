class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        for(int i=nums.size()-1;i>=1;i--) nums[i]-=nums[i-1];
        int res=0;
        for(int i=1;i<n;i++){
            int j=i;
            while(j<n && nums[j]==nums[i]) j++;
            int k=j-i;
            res+=(k-1)*k/2;
            i=j-1;
        }
        return res;
    }
};