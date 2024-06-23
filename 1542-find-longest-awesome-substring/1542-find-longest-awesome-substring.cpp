class Solution {
public:
    const int D=10;
    int longestAwesome(string s) {
        int n=s.size();
        vector<int>pos(1<<D,n);
        pos[0]=-1;
        int ans=0,pre=0;
        for(int i=0;i<n;i++){
            pre^=1<<(s[i]-'0');
            for(int d=0;d<D;d++)
                ans=max(ans,i-pos[pre^(1<<d)]);
            ans=max(ans,i-pos[pre]);
            if(pos[pre]==n) pos[pre]=i;
        }
        return ans;
    }
};