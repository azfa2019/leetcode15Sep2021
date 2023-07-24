class Solution {
public:
    double myPow(double x, int n) {
        typedef long long LL;
        bool isminus=n<0;
        double res=1;
        for(LL k=abs(n);k;k>>=1){
            if(k&1)  res*=x;
            x*=x;
        }
        if(isminus) res=1/res;
        return res;
    }
};