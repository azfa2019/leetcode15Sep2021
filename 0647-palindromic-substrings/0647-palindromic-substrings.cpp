class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=i,k=i;j>=0 && k<n;j--,k++){
                if(s[j]!=s[k]) break;
                res++;
            }
            for(int j=i,k=i+1;j>=0 && k<n;j--,k++){
                if(s[j]!=s[k]) break;
                res++;
            }
        }
        return res;
    }
};