class Solution {
public:
    int gcd(int a,int b){
        return b?gcd(b,a%b):a;
    }
    int mirrorReflection(int p, int q) {
        int t=p*q/gcd(p,q);
        int x=t/q,y=t/p;
        if(x%2){
            if(y%2) return 1;
            else return 0;
        }
        return 2;
    }
};