class Solution {
    public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int l=0;l<n/2;l++){
            int cs=l,ce=n-1-l;
            int rs=l,re=n-1-l;
            for(int i=1;i<=n-1-2*l;i++){
                int tmp=matrix[rs][cs+i];
                matrix[rs][cs+i]=matrix[re-i][cs];
                matrix[re-i][cs]=matrix[re][ce-i];
                matrix[re][ce-i]=matrix[rs+i][ce];
                matrix[rs+i][ce]=tmp;
            }
        }
    }
};
// x 15 13 2 5 x  l=1, 
//1 4 8
//6 5 3
//7 2 9