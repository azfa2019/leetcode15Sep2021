class Solution {
public:
    double champagneTower(int p, int r, int c) {
        vector<vector<double>>f(r+1,vector<double>(r+1));
        f[0][0]=p;
        for(int i=0;i<r;i++){
            for(int j=0;j<=i;j++){
                if(f[i][j]>1.){
                    double x=(f[i][j]-1)/2.0;
                    f[i+1][j]+=x;
                    f[i+1][j+1]+=x;
                }
            }
        }
        return min(1.0,f[r][c]);
    }
};