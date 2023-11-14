class Solution {
public:
    int countPalindromicSubsequence(string s) {
        map<char,int>first,last;
        int n=s.size();
        for(int i=0;i<n;i++) {
            if(first.count(s[i])) last[s[i]]=i;
            else first[s[i]]=i;
        }
        int res=0;
        for(char i='a';i<'a'+26;i++){
            if(!first.count(i)||!last.count(i)) continue;
            int tl=first[i],tr=last[i];
            vector<int>count(26);
            for(int j=tl+1;j<tr;j++) count[s[j]-'a']=1;
            for(int j=0;j<26;j++) if(count[j]) res++;
        }
        return res;
    }
};