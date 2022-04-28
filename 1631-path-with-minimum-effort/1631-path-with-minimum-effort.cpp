class Solution {
    int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};   
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        int l=0,r=1e6,ans=0;
        while(l<r){
            int mid=(l+r)/2;
            queue<pair<int,int>>q;
            q.push({0,0});
            vector<int>seen(m*n);
            seen[0]=1;
            while(!q.empty()){
                auto [x,y]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && !seen[nx*n+ny] && abs(heights[x][y]-heights[nx][ny])<=mid){
                        q.push({nx,ny});
                        seen[nx*n+ny]=1;
                    }
                }
            }
                                                               if(seen[m*n-1]) ans=mid,r=mid;
                                                               else l=mid+1;
        }
                                                               return ans;
    }
};