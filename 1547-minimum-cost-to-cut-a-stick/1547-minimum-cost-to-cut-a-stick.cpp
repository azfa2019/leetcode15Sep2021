class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size(),2e9));
        for(int i=0;i<cuts.size()-1;i++) dp[i][i+1]=0;
        return dfs(0,cuts.size()-1,dp,cuts);
    }
    int dfs(int i,int j,vector<vector<int>>&dp,vector<int>&cuts){
        if(dp[i][j]<2e9) return dp[i][j];
        for(int k=i+1;k<j;k++)
            dp[i][j]=min(dp[i][j],dfs(i,k,dp,cuts)+dfs(k,j,dp,cuts)+cuts[j]-cuts[i]);
        return dp[i][j];
    }
};