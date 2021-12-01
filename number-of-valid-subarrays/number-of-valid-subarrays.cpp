class Solution {
  public:
  int validSubarrays(vector<int>& nums) {
    nums.push_back(INT_MIN);
    int n=nums.size();
    stack<int>stack;
    int count=0;
    for(int i=0;i<n;i++){
      while(!stack.empty() && nums[stack.top()]>nums[i]){
        count+=i-stack.top();
        stack.pop();
      }
      stack.push(i);
    }
    return count;
  }
};
// 1 4 5 7 3
// i       j
// 1 3
// i       j