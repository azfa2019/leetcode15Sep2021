const int M=1e9+7;
class Solution {
public:
    int countRoutes(vector<int>& ls, int start, int finish, int fuel) {
        int n=ls.size();
        vector<vector<int>>dp(n,vector<int>(fuel+1,0));
        //到达第i个城市，还剩j格油的方案数
        dp[start][fuel]=1;
        for(int i=fuel-1;i>=0;i--)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++){
                    if(j==k) continue;
                    int dist=abs(ls[j]-ls[k]);
                    if(i+dist<=fuel){
                        ////从k出发，到j，还剩i的油
                        dp[j][i]+=dp[k][i+dist];
                        dp[j][i]%=M;
                    }
                }
        int res=0;
        for(int i=0;i<=fuel;i++) res+=dp[finish][i], res%=M;
        return res;
    }
};