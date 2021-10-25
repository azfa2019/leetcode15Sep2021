class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
      unordered_map<int,int>map0;
      stack<int>stack0;
      int n=nums.size();
      vector<int>ans(n);
      for(int i=2*n-1;i>=0;i--){
        while(!stack0.empty() && nums[i%n]>=stack0.top()) stack0.pop();
        ans[i%n]=stack0.empty()?-1:stack0.top();
        stack0.push(nums[i%n]);
      }
      return ans;
    }
};