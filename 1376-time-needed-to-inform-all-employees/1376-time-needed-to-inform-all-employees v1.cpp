class Solution {
    int ans=INT_MIN;
    vector<int>informTime;
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>report(n);
        this->informTime=informTime;
        for(int i=0;i<n;i++){
            if(manager[i]==-1) continue;
            report[manager[i]].push_back(i);
        }
        int curSum=informTime[headID];
        dfs(headID,curSum,report);
        return ans;
    }
    void dfs(int node,int curSum,vector<vector<int>>&report){
        if(report[node].size()==0) {
            ans=max(ans,curSum);
            return;
        }
        for(int next:report[node]){
            dfs(next,curSum+informTime[next],report);
        }
    }
};
