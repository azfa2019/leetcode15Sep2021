class Solution {
public:
    string reverseWords(string s) {
        int i=0,j,n=s.size();
        while(s[i]==' ') i++;
        j=i;
        string res="";
        for(;i<n;i++){
            if(s[i]==' ') continue;
            j=i+1;
            while(j<n && s[j]!=' ') j++;
            res=s.substr(i,j-i)+" "+res;
            i=j;
        }
        res.pop_back();
        return res;
    }
};