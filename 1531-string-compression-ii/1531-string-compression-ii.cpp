int cache[101][27][101][101];
class Solution {
public:
    
    string s;
    int getLengthOfOptimalCompression(string s_, int k) {
       memset(cache,-1,sizeof cache);
        s=s_;
        return dp(0,26,0,k);
    }
    int dp(int i, int last,int len,int k){
        if(k<0) return INT_MAX/2;
        if(i>=s.size()) return 0;
        int& ans=cache[i][last][len][k];
        if(ans!=-1) return ans;
        if(s[i]-'a'==last) {
            int carry=(len==1||len==9||len==99);
            ans=carry+dp(i+1,last,len+1,k);
        }else{
            ans=min(1+dp(i+1,s[i]-'a',1,k),dp(i+1,last,len,k-1));
        }
        return ans;
    }
};