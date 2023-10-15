class Solution {
public:
    typedef long long LL;
    long long maximumBooks(vector<int>& v) {
        int n=v.size();
        stack<int>stk;
        LL res=0;
        vector<LL>f(n);
        for(int i=0;i<n;i++){
            while(stk.size()&&v[stk.top()]>v[i]-(i-stk.top())) stk.pop();
            if(stk.size()){
                int len=i-stk.top();
                f[i]=f[stk.top()]+(LL)(v[i]+v[i]-len+1)*len/2;
            }else{
                int len=v[i]-i<=0?v[i]:i+1;
                f[i]=(LL)(v[i]+v[i]-len+1)*len/2;
            }
            res=max(res,f[i]);
            stk.push(i);
        }
        return res;
    }
};