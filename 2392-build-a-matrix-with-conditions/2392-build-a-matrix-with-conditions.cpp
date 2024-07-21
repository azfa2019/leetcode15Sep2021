class Solution {
public:
    vector<int>topsort(int k,vector<vector<int>>&edges){
        vector<vector<int>>g(k);
        vector<int>in(k);
        for(auto&e:edges){
            int x=e[0]-1,y=e[1]-1;
            g[x].push_back(y);
            ++in[y];
        }
        vector<int>order;
        queue<int>q;
        for(int i=0;i<k;i++)
            if(!in[i]) q.push(i);
        while(q.size()){
            int x=q.front();q.pop();
            order.push_back(x);
            for(int y:g[x])
                if(--in[y]==0) q.push(y);
        }
        return order;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        auto row=topsort(k,rowConditions),col=topsort(k,colConditions);
        if(row.size()<k||col.size()<k) return {};
        vector<int>pos(k);
        for(int i=0;i<k;i++) pos[col[i]]=i;
        vector<vector<int>>ans(k,vector<int>(k));
        for(int i=0;i<k;i++)
            ans[i][pos[row[i]]]=row[i]+1;
        return ans;
    }
};