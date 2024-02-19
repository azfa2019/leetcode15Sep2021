class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long res=1;
        for(int i=0;i<32;i++){
            if(res==n) return true;
            res=res*2;
        }
        return false;
    }
};