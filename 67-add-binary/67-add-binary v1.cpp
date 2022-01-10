class Solution {
    public:
    string addBinary(string a, string b) {

        if(a.size()<b.size()) {
            auto tmp=b;
            b=a;
            a=tmp;
        }
        int n=a.size(),m=b.size();
        for(int i=0;i<n-m;i++) b="0"+b;
        int carry=0;
        string ans(n,0);
        for(int i=n-1;i>=0;i--){
            if(a[i]-'0'+b[i]-'0'+carry>=2 ) 
                ans[i]='0'+(a[i]-'0'+b[i]-'0'+carry)%2,carry=1;
            else
                ans[i]='0'+a[i]-'0'+b[i]-'0'+carry,carry=0;
            }
        if(carry==1) ans="1"+ans;
        return ans;
    }
};
