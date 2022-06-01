class Solution {
public:
    int minKnightMoves(int x, int y) {
        int dir[8][2]= {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
        vector<vector<bool>>vis(700,vector<bool>(700));
        queue<pair<int,int>>q;
        q.push({310,310});
        vis[310][310]=true;
        x+=310,y+=310;
        int ans=0;
        while(q.size()){
            int l=q.size();
            while(l--){
                auto t=q.front();q.pop();
                if(t.first==x && t.second==y) return ans;
                for(auto& d:dir){
                    int a=t.first+d[0],b=t.second+d[1];
                    if(!vis[a][b]){
                        vis[a][b]=true;
                        q.push({a,b});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};