class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n=a.size(),m=a[0].size(),k=b[0].size();
        unordered_map<int,int>am;
        vector<vector<int>>res(n,vector<int>(k,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(!a[i][j]) continue;
                int idx=i*m+j;
                am[idx]=a[i][j];
            }
        for(auto aij:am){
            int va=aij.second,aidx=aij.first,ai=aidx/m,aj=aidx%m;
            for(int j=0;j<k;j++)
                res[ai][j]+=va*b[aj][j];
        }
        return res;
    }
};