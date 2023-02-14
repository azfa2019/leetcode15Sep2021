class Solution {
public:
    string addBinary(string a, string b) {
        int t=0;
        vector<int>A,B,C;
        for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
        for(int i=b.size()-1;i>=0;i--) B.push_back(b[i]-'0');
        if(A.size()<B.size()) return addBinary(b,a);
        for(int i=0;i<A.size();i++){
            t+=A[i];
            if(i<B.size()) t+=B[i];
            C.push_back(t%2);
            t/=2;
        }
        if(t) C.push_back(t);
        string res;
        for(int i=C.size()-1;i>=0;i--) res+=C[i]+'0';
        return res;
    }
};