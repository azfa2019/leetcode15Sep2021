class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        int r=sqrt(n);
        if(r*r!=n) return false;
        return ((1<<30)%n)==0;
    }
};