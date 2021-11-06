class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
      unordered_set<int>set0;
      for(int num:nums){
        if(set0.find(num)!=set0.end()) set0.erase(num);
        else set0.insert(num);
      }
      vector<int>ans;
      for(int num:set0) ans.push_back(num);
      return ans;
    }
};