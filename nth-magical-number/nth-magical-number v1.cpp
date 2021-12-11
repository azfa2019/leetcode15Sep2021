class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long M=1e9+7;
        long lcm=a*b/gcd(a,b);
        long numInterval= n/(lcm/a+lcm/b-1);
        long numMagic=numInterval*(lcm/a+lcm/b-1);
        long numRemainCount=n-numMagic;
        if(numRemainCount==0) return numInterval*lcm%M;
        
        int i=1,j=1;
        long remain;
        long count=0;
        while(count<numRemainCount){
            if(a*i<b*j) {
                remain=a*i;
                i++;
            }else{
                remain=b*j;
                j++;
            }
            count++;
        }
        return (lcm*numInterval%M+remain)%M;
    }
};
