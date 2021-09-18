class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set<int> set(nums.begin(),nums.end());
      int maxcount=0;
      for(int i:set){
        if(set.find(i-1)!=set.end()) continue;
        int count=0;
        while(set.find(i)!=set.end()){
          count++;
          i++;
        }
        maxcount=max(maxcount,count);
      }
      return maxcount;
    }
};