class Solution {
  public:
  int longestConsecutive(vector<int>& nums) {
      unordered_set<int>st(nums.begin(),nums.end());
      int ans=0;
      for(int num:nums){
          if(st.find(num-1)!=st.end()) continue;
          int count=1;
          while(st.find(num)!=st.end()){
              num++;
              ans=max(count,ans);
              count++;
          }
      }
      return ans;
  }
};