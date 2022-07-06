class Solution {
public:
    int fib(int n) {
        vector<int>f(n+1,0);
        
        int a=0,b=1;
        while(n--){
            int c=a+b;
            a=b,b=c;
        }
        return a;
    }
};