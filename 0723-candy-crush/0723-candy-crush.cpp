class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& b) {
        int m=b.size(),n=b[0].size();
        while(true){
            vector<pair<int,int>>del;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(!b[i][j]) continue;
                    int x0=i,x1=i,y0=j,y1=j;
                    while(x0>=0&&x0>i-3&&b[x0][j]==b[i][j]) x0--;
                    while(x1<m&&x1<i+3&&b[x1][j]==b[i][j]) x1++;
                    while(y0>=0&&y0>j-3&&b[i][y0]==b[i][j]) y0--;
                    while(y1<n&&y1<j+3&&b[i][y1]==b[i][j]) y1++;
                    if(x1-x0>3||y1-y0>3) del.push_back({i,j});
                }
            }
            if(del.empty()) break;
            for(auto a:del) b[a.first][a.second]=0;
            for(int j=0;j<n;j++) {
                int t=m-1;
                for(int i=m-1;i>=0;i--) 
                    if(b[i][j]) swap(b[t--][j],b[i][j]);
            }
        }
        return b;
    }
};