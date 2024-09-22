class Solution {
public:
    int findKthNumber(int n, int k) {
        int pre=1;
        while(k>1){
            int cnt=f(pre,n);
            if(k>cnt){
                k-=cnt;
                pre++;
            }else{
                k--;
                pre*=10;
            }
        }
        return pre;
    }
    int f(int pre,int n){
        long long p=1;
        auto A=to_string(n),B=to_string(pre);
        int dt=A.size()-B.size();
        int res=0;
        for(int i=0;i<dt;i++) res+=p,p*=10;
        A=A.substr(0,B.size());
        if(A==B) res+=n-pre*p+1;
        else if(A>B) res+=p;
        return res;
    }
};