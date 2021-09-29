class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
      vector<bool>dp(3000,false);
      dp[0]=true;
      int sum=0;
      for(int stone:stones){
        sum+=stone;
      //cout<<sum<<endl;
        for(int weight=sum;weight>=stone;weight--){
          if(dp[weight-stone]) dp[weight]=true;
        }
      }
      for(int w=sum/2;w>=0;--w){
        if(dp[w]) return sum-2*w;
      }
      return 0;
    }
};