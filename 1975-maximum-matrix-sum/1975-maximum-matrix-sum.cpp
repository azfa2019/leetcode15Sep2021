class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int minn=abs(matrix[0][0]);
        long long ans=0;
        bool flag=false;
        for(auto&v:matrix)
            for(int &num:v){
                if(num<0) flag=!flag,num=-num;
                ans+=num;
                minn=min(num,minn);
            }
        if(flag) return ans-2*minn;
        return ans;
    }
};