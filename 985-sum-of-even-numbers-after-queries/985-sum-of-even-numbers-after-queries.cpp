class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int even=0;
        vector<int>res;
        for(int num:nums) if(num%2==0) even+=num;
        for(auto q:queries){
            int val=q[0],index=q[1];
            if(nums[index]%2==0) even-=nums[index];
            nums[index]+=val;
            if(nums[index]%2==0) even+=nums[index];
            res.push_back(even);
        }
        return res;
    }
};