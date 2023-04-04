class Solution {
public:
    int partitionString(string s) {
        int n=s.size();
        int cnt[26];
        memset(cnt,0,sizeof cnt);
        int res=0;
        for(int i=0;i<n;i++){
            if(cnt[s[i]-'a']){
                res++;
                memset(cnt,0,sizeof cnt);
                //cout<<i<<endl;
            }
            cnt[s[i]-'a']++;
        }
        return res+1;
    }
};