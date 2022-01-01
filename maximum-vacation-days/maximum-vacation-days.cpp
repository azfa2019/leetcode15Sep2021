class Solution {
    vector<vector<int>> flights;
    vector<vector<int>> days;
    int m,n;
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        this->flights=flights;
        this->days=days;
        this-> m=flights.size(),this->n=days[0].size();
        vector<vector<int>>memo(m,vector<int>(n,INT_MIN));
        return dfs(0,0,memo);
    }
    int dfs(int curcity,int wk,vector<vector<int>>&memo){
        if(wk==n) return 0;
        if(memo[curcity][wk]!=INT_MIN) return memo[curcity][wk];
        int ans=0;
        for(int i=0;i<m;i++){
            if(flights[curcity][i]==1 || curcity==i){
                int vac=days[i][wk]+dfs(i,wk+1,memo);
                ans=max(ans,vac);
            }
        }
        memo[curcity][wk]=ans;
        return ans;
    }
};