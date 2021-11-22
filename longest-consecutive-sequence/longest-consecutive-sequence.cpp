class Solution {
  public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int>set0(nums.begin(),nums.end());
    int maxLen=0;
    for(int num:set0){
      if(set0.find(num-1)!=set0.end()) continue;
      int i=0;
      while(set0.find(i+num)!=set0.end()){
        maxLen=max(maxLen,i+1);
        i++;
      }
    }
    return maxLen;
  }
};