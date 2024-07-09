class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        int n=c.size();
        if(n==1) return c[0][1];
        double res=0;
        int cur=c[0][0];
        for(int i=0;i<n;i++){
            cur=max(cur,c[i][0])+c[i][1];
            res+=cur-c[i][0];
        }
        return (res)/n;
    }
};