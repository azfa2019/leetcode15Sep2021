class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size(),m=strs[0].size();
        if(n==1) return 0;
        vector<bool>st(m,true);
        int res=0;
        for(int i=1;i<n;i++)
            for(int j=0;j<m;j++){
                if(!st[j]) continue;
                if(strs[i][j]-strs[i-1][j]<0) st[j]=false,res++;
            }
        return res;
    }
};