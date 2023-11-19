class Solution {
public:
    typedef pair<int,int> PII;
    int reductionOperations(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++) 
            if(nums[i]>nums[i+1]) cnt+=i+1;
        return cnt;
    }
};