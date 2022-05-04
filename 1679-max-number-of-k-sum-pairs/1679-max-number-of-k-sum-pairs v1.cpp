class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0,r=n-1;
        int res=0;
        while(l<r){
            int s=nums[l]+nums[r];
            if(s<k) l++;
            else if(s>k) r--;
            else res++,l++,r--;
        }
        return res;
    }
};
