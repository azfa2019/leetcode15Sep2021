class Solution {
public:
    long sum(long x,int cnt){
        return x>=cnt?(x+x-cnt+1)*cnt/2:(1+x)*x/2+cnt-x;
    }
    int maxValue(int n, int index, int maxSum) {
        int l=1,r=maxSum;
        while(l<r){
            int mid=(l+r+1)>>1;
            if(sum(mid-1,index)+sum(mid,n-index)<=maxSum) l=mid;
            else r=mid-1;
        }
        return l;
    }
};