class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>cnt;
        int maxc=0;
        for(auto c:s){
            cnt[c]++;
            maxc=max(maxc,cnt[c]);
        }
        int n=s.size();
        if (maxc>(n+1)/2) return "";
        string res(n,' ');
        int i=1,j=0;
        for(char c='a';c<='z';c++){
            if(cnt[c]<=n/2) {
                while(cnt[c]&&i<n){
                    res[i]=c;
                    cnt[c]--;
                    i+=2;
                }
            }
            while(cnt[c]&&j<n){
                res[j]=c;
                cnt[c]--;
                j+=2;
            }
        }
        return res;
    }
};