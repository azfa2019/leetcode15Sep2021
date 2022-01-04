class Solution {
    public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int pos=31;
        while(pos >=0 && ((n>>pos)&1)==0) pos--;
        int ans=0;
        for(int i=0;i<=pos;i++){
            if(((n>>i)&1)==0) ans|=(1<<i);
        }
        return ans;
    }
};