class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>f(26);
        int res=-1;
        for(char c:s){
            f[c-'a']++;
        }
        for(int i=s.size()-1;i>=0;i--) if(f[s[i]-'a']==1) res=i;
        return res;
    }
};