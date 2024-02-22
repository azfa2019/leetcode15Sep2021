class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>trout(n+1);
        vector<int>trin(n+1);
        for(auto t:trust) {
            trout[t[0]]++;
            trin[t[1]]++;
        }
        int res=-1;
        for(int i=1;i<=n;i++) if(trout[i]==0 && trin[i]==n-1) res=i;
        return res;
    }
};