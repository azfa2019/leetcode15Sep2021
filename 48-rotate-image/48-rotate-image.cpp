class Solution {
    public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int start=0,end=n-1;
        while(start<end){
            for(int i=start,j=end;i<=end-1,j>=start+1;i++,j--){
                int tmp=matrix[start][i];
                matrix[start][i]=matrix[j][start];
                matrix[j][start]=matrix[end][j];
                matrix[end][j]=matrix[i][end];
                matrix[i][end]=tmp;
            }
            start++,end--;
        }
    }
};
//    s   e
//  s[1,2,3],
//   [4,5,6],
//  e[7,8,9]