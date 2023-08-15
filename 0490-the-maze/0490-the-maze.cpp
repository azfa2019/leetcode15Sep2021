class Solution {
    vector<int>dx={1,0,-1,0},dy={0,-1,0,1};
    
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& dst) {
        int n=maze.size(),m=maze[0].size();
        vector<vector<bool>>visit(n,vector<bool>(m,false));
        return helper(maze,start[0],start[1],dst,visit);
    }
    bool helper(vector<vector<int>>& maze, int& curx,int& cury, vector<int>& dst,vector<vector<bool>>&visit){
        if(curx==dst[0]&&cury==dst[1]) return true;
        if(visit[curx][cury]) return false;
        visit[curx][cury]=true;
        for(int i=0;i<4;i++){
            int x=curx,y=cury;
            while(x+dx[i]>=0 && 
                 x+dx[i]<maze.size() &&
                 y+dy[i]>=0 &&
                 y+dy[i]<maze[0].size()&&
                 maze[x+dx[i]][y+dy[i]]!=1){
                x+=dx[i],y+=dy[i];
            }
         if(helper(maze,x,y,dst,visit)) return true;
    
        }
        return false;
    }
};