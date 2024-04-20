class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& l) {
        int n=l.size(),m=l[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(!l[i][j]) continue;
                int r=i,c=j;
                while(r+1<n&&l[r+1][j]) r++;
                while(c+1<m&&l[r][c+1]) c++;
                ans.push_back({i,j,r,c});
                for(int x=i;x<=r;x++)
                    for(int y=j;y<=c;y++)
                        l[x][y]=0;
            }
        return ans;
    }
};