class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        
        for(auto& w:words)
            kmp(text,w);
        sort(ans.begin(),ans.end());
        return ans;
    }
    void kmp(string s,string p){
        int n=s.size(),m=p.size();
        s="#"+s;
        p="#"+p;
        vector<int>ne(m+1);
        for(int i=2,j=0;i<=m;i++){
            while(j && p[i]!=p[j+1]) j=ne[j];
            if(p[i]==p[j+1]) j++;
            ne[i]=j;
        }
        for(int i=1,j=0;i<=n;i++){
            while(j&&s[i]!=p[j+1]) j=ne[j];
            if(s[i]==p[j+1]) j++;
            if(j==m){
                ans.push_back({i-m,i-1});
                j=ne[j];
            }
        }
        
    }
};