class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
      int prefix=0,ans=0;
      unordered_map<int,int>map;
      map[0]=1;
      for(int num:nums){
        prefix=(prefix+num%k+k)%k;
        ans+=map[prefix];
        map[prefix]++;
      }
      return ans;
    }
};