class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>hash;
        for(int num:nums) {
            hash[num]++;
            if(hash[num]>n/2) return num;
        }
        return -1;
    }
};