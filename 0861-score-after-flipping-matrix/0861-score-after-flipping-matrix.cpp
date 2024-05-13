class Solution {
public:
    int matrixScore(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        for(int i=0;i<n;i++)
            if(!g[i][0])
                for(int j=0;j<m;j++)
                    g[i][j]^=1;
        int res=(1<<m-1)*n;
        for(int i=1;i<m;i++){
            int cnt=0;
            for(int j=0;j<n;j++)
                if(g[j][i]) cnt++;
            res+=(1<<m-1-i)*max(cnt,n-cnt);
        }
        return res;
    }
};