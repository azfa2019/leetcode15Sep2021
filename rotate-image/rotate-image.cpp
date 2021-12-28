class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int start=0,end=n-1;
        while(start<=end){
            for(int j=start,i=end;j<=end-1,i>=start+1;j++,i--){
                int tmp=matrix[start][j];
                matrix[start][j]=matrix[i][start];
                matrix[i][start]=matrix[end][i];
                matrix[end][i]=matrix[j][end];
                matrix[j][end]=tmp;
            }
            start++,end--;
        }
    }
};