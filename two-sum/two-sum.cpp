class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int num=nums[i];
            if(mp.find(target-num)!=mp.end()) return {mp[target-num],i};
            mp[num]=i;
        }
        return {-1,-1};
    }
};