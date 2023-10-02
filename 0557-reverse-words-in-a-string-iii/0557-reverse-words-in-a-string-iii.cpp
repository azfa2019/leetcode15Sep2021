class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        string res="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' ') {
                res=s[i]+res;
                continue;
            }
            int j=i;
            while(j<s.size()&&s[j]!=' ') j++;
            res=s.substr(i,j-i)+res;
            i=j-1;
        }
        return res;
    }
};