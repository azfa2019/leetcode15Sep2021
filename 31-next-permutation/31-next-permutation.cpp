class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int k=n-1;
        while(k>0 && nums[k]<=nums[k-1]) k--;
        if(k<=0) reverse(nums.begin(),nums.end());
        else{
            int t=k;
            while(t<=n-1 && nums[t]>nums[k-1]) t++;
            swap(nums[t-1],nums[k-1]);
            reverse(nums.begin()+k,nums.end());
        }
    }
};