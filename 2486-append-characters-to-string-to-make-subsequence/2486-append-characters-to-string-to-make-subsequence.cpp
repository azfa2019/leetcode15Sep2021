class Solution {
public:
    int appendCharacters(string s, string t) {
        int n=s.size(),m=t.size();
        int p1=0,p2=0;
        for(;p1<n;p1++){
            if(s[p1]==t[p2]) p2++;
        }
        return m-p2;
    }
};