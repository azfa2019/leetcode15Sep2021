class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      int n=nums.size();
      unordered_map<int,int>map;
      //prefix: sum and frequency
      int sum=0,ans=0;
      map[0]=1;
      for(int num:nums){
        sum+=num;
        if(map.find(sum-k)!=map.end())
          ans+=map[sum-k];
        map[sum]++;
      }
      return ans;
    }
};