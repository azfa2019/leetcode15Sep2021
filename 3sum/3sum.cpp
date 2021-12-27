class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int left=i+1,right=n-1;
            while(left<right){
                if(left<right && nums[left]+nums[right]+nums[i]<0) left++;
                else if(left<right && nums[left]+nums[right]+nums[i]>0) right--;
                else {
                    ans.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    while(left<right && nums[left]==nums[left-1]) left++;
                    right--;
                    while(left<right && nums[right]==nums[right+1]) right--;
                }
            }
        }
        return ans;
    }
};