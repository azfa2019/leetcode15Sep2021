class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>din(n+1),dout(n+1);
        for(auto t:trust) dout[t[0]]++,din[t[1]]++;
        int res=-1;
        for(int i=1;i<=n;i++) 
            if(din[i]==n-1 && dout[i]==0) res=i;
        return res;
    }
};