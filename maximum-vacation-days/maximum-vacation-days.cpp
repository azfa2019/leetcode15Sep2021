class Solution {
    vector<vector<int>> flights;
    vector<vector<int>> days;
    int m,n;
    vector<vector<int>>memo;
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        
        this->flights=flights;
        this->days=days;
        this->m=flights.size();
        this->n=days[0].size();
        memo=vector<vector<int>>(m,vector<int>(n,INT_MIN));
        return dfs(0,0);
    }
    int dfs(int curcity,int wk){
        if(wk==n) return 0;
        if(memo[curcity][wk]!=INT_MIN) return memo[curcity][wk];
        int ans=0;
        for(int i=0;i<m;i++){
            if(flights[curcity][i]==1 || curcity==i){
                int vac=days[i][wk]+dfs(i,wk+1);
                ans=max(ans,vac);
            }
        }
        memo[curcity][wk]=ans;
        return ans;
    }
};