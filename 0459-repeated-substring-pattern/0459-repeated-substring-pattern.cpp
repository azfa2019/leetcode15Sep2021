class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        s=' '+s;
        vector<int>ne(n+1);
        for(int i=2,j=0;i<=n;i++){
            while(j && s[i]!=s[j+1]) j=ne[j];
            if(s[i]==s[j+1]) j++;
            ne[i]=j;
        }
        int t=n-ne[n];
        return t<n&&n%t==0;
    }
};