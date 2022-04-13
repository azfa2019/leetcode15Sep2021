class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>res(n,vector<int>(n));
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        for(int x=0,y=0,i=0,d=1;i<n*n;i++){
            res[x][y]=i+1;
            int a=x+dx[d],b=y+dy[d];
            if(a<0 || a==n||b<0||b==n||res[a][b]){
                d=(d+1)%4;
                a=x+dx[d],b=y+dy[d];
            }
            x=a,y=b;
        }
        return res;
    }
};