class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& p) {
        if(p.empty()||p[0].empty()) return 0;
        int m=p.size(),n=p[0].size();
        vector<int>rowcnt(m,0),colcnt(n,0);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(p[i][j]=='B') rowcnt[i]++,colcnt[j]++;
        int res=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(p[i][j]=='B')
                    if(rowcnt[i]==1&&colcnt[j]==1) res++;
        return res;
    }
};