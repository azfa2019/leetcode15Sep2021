class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n<=1) return n;
        int pos=0;
        for(int i=0;i<32;i++)
            if((n>>i)&1) pos=i;
        int x=(1<<(pos+1))-1;
        int y=n-(1<<pos);
        return x-minimumOneBitOperations(y);
    }
};