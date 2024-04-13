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
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>h(n,vector<int>(m));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') {
                    if(i) h[i][j]=1+h[i-1][j];
                    else h[i][j]=1;
                    }
            }
        int res=0;
        for(int i=0;i<n;i++) res=max(res,largestRectangleArea(h[i]));
        return res;
    }
};