class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        for(int b=-(n-1);b<=m-1;b++){
            vector<int>q;
            for(int x=0,y=b;x<n&&y<m;x++,y++)
                if(y>=0) q.push_back(g[x][y]);
            sort(q.begin(),q.end());
            for(int x=0,y=b,k=0;x<n&&y<m;x++,y++)
                if(y>=0) g[x][y]=q[k++];
        }
        return g;
    }
};