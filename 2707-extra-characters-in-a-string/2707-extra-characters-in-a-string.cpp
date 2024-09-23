class Solution {
public:
    int minExtraChar(string s, vector<string>& d) {
        unordered_set<string>S(d.begin(),d.end());
        int n=s.size();
        vector<int>f(n+1);
        for(int i=0;i<n;i++){
            f[i+1]=f[i]+1;
            for(int j=0;j<=i;j++){
                if(S.count(s.substr(j,i-j+1))){
                    f[i+1]=min(f[i+1],f[j]);
                }
            }
        }
        return f[n];
    }
};