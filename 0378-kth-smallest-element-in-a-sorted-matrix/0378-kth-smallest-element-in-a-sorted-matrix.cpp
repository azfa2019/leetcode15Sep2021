class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        function<bool(int)>check=[&](int mid)->bool{
            int i=n-1,j=0,num=0;
            while(i>=0 && j<n){
                if(matrix[i][j]<=mid) num+=i+1,j+=1;
                else i-=1;
            }
            return num>=k;
        };
        int l=matrix[0][0],r=matrix[n-1][n-1];
        while(l<r){
            int mid=(l+r)>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        return l;
    }
};