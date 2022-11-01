class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        for(int j=0;j<m;j++){
            int t=mat[0][j];
            int i=1;
            for(;i<n;i++){
                if(helper(mat[i],t)) continue;
                else break;
            }
            if(i==n) return t;
        }
        return -1;
    }
    bool helper(vector<int>row,int t){
        int l=0,r=row.size()-1;
        while(l<r){
            int mid=l+r>>1;
            if(row[mid]<t) l=mid+1;
            else r=mid;
        }
        if(row[l]==t) return true;
        return false;
    }
};