class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        unordered_map<int,int>mp;
        for(auto trip:trips){
            mp[trip[1]]-=trip[0];
            mp[trip[2]]+=trip[0];
        }
        vector<pair<int,int>>nums(mp.begin(),mp.end());
        sort(nums.begin(),nums.end());
        for(auto e:nums){
            capacity+=e.second;
            if(capacity<0) return false;
        }
        return true;
    }
};