class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        int l=0,r=1e6;
        int res=0;
        int dx[4]={1,0,-1,0};
        int dy[4]={0,-1,0,1};
        while(l<r){
            int mid=(l+r)>>1;
            queue<pair<int,int>>q;
            q.push({0,0});
            vector<bool>st(m*n);
            st[0]=1;
            while(q.size()){
                auto [x,y]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && !st[nx*n+ny] && abs(heights[x][y]-heights[nx][ny])<=mid) q.push({nx,ny}),st[nx*n+ny]=1;
                }
            }
            if(st[m*n-1]) res=mid,r=mid;
            else l=mid+1;
        }
        return res;
    }
};
