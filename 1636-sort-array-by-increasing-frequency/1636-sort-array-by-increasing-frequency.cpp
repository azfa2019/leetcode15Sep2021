class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>hash;
        for(auto& num:nums) hash[num]++;
        sort(nums.begin(),nums.end(),[&](const int a, const int b){
            if(hash[a]==hash[b]) return a>b;
            return hash[a]<hash[b];
        });
        return nums;
    }
};