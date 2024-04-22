class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& p) {
        vector<int>res;
        int cnt=0;
        vector<int>fa(m*n,-1);
        int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
        for(auto& e:p){
            int id=n*e[0]+e[1];
            if(fa[id]!=-1) {
                res.push_back(cnt);
                continue;
            }
            fa[id]=id;
            cnt++;
            for(int i=0;i<4;i++){
                int x=e[0]+dx[i],y=e[1]+dy[i],curid=n*x+y;
                if(x<0||x>=m||y<0||y>=n||fa[curid]==-1) continue;
                int px=find(fa,curid),py=find(fa,id);
                if(px!=py) fa[px]=py,cnt--;
            }
            res.push_back(cnt);
        }
        return res;
    }
    int find(vector<int>&fa,int id){
        return (id==fa[id])?id:find(fa,fa[id]);
    }
};