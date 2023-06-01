class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n=prob.size();
        vector<double>dp(target+1);
        dp[0]=1.;
        for(int i=0;i<n;i++){
            for(int j=min(i+1,target);j>=0;j--){
                dp[j]=dp[j]*(1-prob[i])+(j>0?dp[j-1]:0)*prob[i];
            }
        }
        return dp[target];
    }
};