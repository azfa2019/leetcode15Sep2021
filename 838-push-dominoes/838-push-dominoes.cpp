class Solution {
public:
    string pushDominoes(string s) {
        s='L'+s+'R';
        int n=s.size();
        vector<int>l(n),r(n);
        for(int i=0,j=0;i<n;i++) {
            if(s[i]!='.') j=i;
            l[i]=j;
        }
        for(int i=n-1,j=n-1;i>=0;i--) {
            if(s[i]!='.') j=i;
            r[i]=j;
        }
        for(int i=0;i<n;i++){
            char L=s[l[i]],R=s[r[i]];
            if(L=='L'&&R=='L') s[i]='L';
            else if(L=='R'&&R=='R') s[i]='R';
            else if(L=='L'&&R=='R') s[i]='.';
            else {
                if(i-l[i]<r[i]-i) s[i]='R';
                else if(i-l[i]>r[i]-i) s[i]='L';
                else s[i]='.';
            }
        }
        return s.substr(1,n-2);
    }
};