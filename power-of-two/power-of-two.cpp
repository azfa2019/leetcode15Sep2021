class Solution {
    public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false; 
        int p=1;
        if(p==n)  return true;
        for(int i=0;i<31;i++){
            p=(p<<1);
            if(p==n)  return true;
        }
        return false;
    }
};