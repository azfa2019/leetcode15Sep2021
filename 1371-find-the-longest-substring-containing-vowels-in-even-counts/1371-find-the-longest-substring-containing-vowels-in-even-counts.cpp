class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int>pos(1<<5,-1);
        pos[0]=0;
        int res=0,cur=0;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c=='a') cur^=(1<<0);
            else if(c=='e') cur^=(1<<1);
            else if(c=='i') cur^=(1<<2);
            else if(c=='o') cur^=(1<<3);
            else if(c=='u') cur^=(1<<4);
            if(pos[cur]!=-1) res=max(res,i-pos[cur]+1);
            else pos[cur]=i+1;
        }
        return res;
    }
};