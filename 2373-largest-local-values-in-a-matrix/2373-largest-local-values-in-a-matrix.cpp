class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& g) {
        int n=g.size();
        vector<vector<int>>res(n-2,vector<int>(n-2));
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
            int c=0;
            for(int x=0;x<3;x++)
                for(int y=0;y<3;y++){
                    int a=i+x,b=j+y;
                    c=max(c,g[a][b]);
                }
            res[i][j]=c;
            }
        }
        return res;
    }
};