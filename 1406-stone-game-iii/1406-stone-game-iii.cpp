class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int dp[50010]={0};
        int n=stoneValue.size();
        int sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=stoneValue[i];
            dp[i]=-2e9;
            for(int j=1;j<=3;j++) dp[i]=max(dp[i],sum-dp[i+j]);
        }
        if(sum-dp[0]==dp[0]) return "Tie";
        else if(sum-dp[0]>dp[0]) return "Bob";
        return "Alice";
    }
};