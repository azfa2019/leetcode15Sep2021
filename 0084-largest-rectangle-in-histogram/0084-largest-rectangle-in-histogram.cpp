class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        vector<int>l(n),r(n);
        stack<int>stk;
        for(int i=0;i<n;i++){
            while(stk.size()&&h[stk.top()]>=h[i]) stk.pop();
            if(stk.empty()) l[i]=-1;
            else l[i]=stk.top();
            stk.push(i);
        }
        stk=stack<int>();
        for(int i=n-1;i>=0;i--){
            while(stk.size()&&h[stk.top()]>=h[i]) stk.pop();
            if(stk.empty()) r[i]=n;
            else r[i]=stk.top();
            stk.push(i);
        }
        int res=0;
        for(int i=0;i<n;i++) res=max(res,h[i]*(r[i]-l[i]-1));
        return res;
    }
};