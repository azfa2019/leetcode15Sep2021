class Solution {
    struct Unit{
        int val;
        int row;
        int col;
        bool operator< (const Unit &rhs) const{
            return val<rhs.val;
        }
    };
    int dir[5]{1,0,-1,0,1};
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        priority_queue<Unit>pq;
        int m=grid.size(),n=grid[0].size();
        int res=min(grid[0][0],grid[m-1][n-1]);
        vector<vector<bool>>st(m,vector<bool>(n,false));
        int i=0,j=0;
        while(!(i==m-1 && j==n-1)){
            st[i][j]=true;
            for(int k=0;k<4;k++){
                int r=i+dir[k];
                int c=j+dir[k+1];
                //if(r==m-1 && c==n-1) return res;
                if(r>=0 && r<m && c>=0 && c<n && st[r][c]==false){
                    st[r][c]=true;
                    pq.push({grid[r][c],r,c});
                }
            }
            auto next=pq.top();pq.pop();
            res=min(res,next.val);
            i=next.row;
            j=next.col;
        }
        return res;
    }
};