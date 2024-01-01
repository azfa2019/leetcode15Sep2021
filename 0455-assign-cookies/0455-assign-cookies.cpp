class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size(),m=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int res=0;
        for(int i=0,j=0;i<n;i++){
            while(j<m && g[i]>s[j]) j++;
            if(j<m && g[i]<=s[j]) res++,j++;
            else break;
        }
        return res;
    }
};