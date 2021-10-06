class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
      int n=nums.size();
      vector<int>freq(n+1,0);
      vector<int>ans;
      for(int n:nums){
        freq[n]++;
        if(freq[n]==2) ans.push_back(n);
      }
      return ans;
    }
};