typedef pair<int,int> PII;
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        stack<int>stk;
        int n=scores.size();
        vector<PII>team;
        for(int i=0;i<n;i++) team.push_back({ages[i],scores[i]});
        sort(team.begin(),team.end());
        int res=0;
        vector<int>dp(n);
        for(int i=0;i<n;i++) {
            dp[i]=team[i].second;
            for(int j=0;j<i;j++){
                if(team[j].second<=team[i].second) dp[i]=max(dp[i],dp[j]+team[i].second);
            }
            res=max(res,dp[i]);
        }
        return res;
    }
};