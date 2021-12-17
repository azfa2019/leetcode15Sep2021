class Solution {
    public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int>stck;
        vector<int>ans(n,-1);
        for(int i=0;i<2*n;i++){
            while(!stck.empty()&& nums[stck.top()]<nums[i%n]){
                ans[stck.top()]=nums[i%n];
                stck.pop();
            }
            stck.push(i%n);
        }
        return ans;
    }
};
