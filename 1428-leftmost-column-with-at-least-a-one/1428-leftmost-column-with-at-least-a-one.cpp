/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &mat) {
        auto dim=mat.dimensions();
        int n=dim[0],m=dim[1];
        int res=m;
        for(int i=0;i<n;i++){
            int l=0,r=m-1;
            while(l<r){
                int mid=l+r>>1;
                if(mat.get(i,mid)==1) r=mid;
                else l=mid+1;
            }
            if(mat.get(i,l)==1) res=min(res,l);
        } 
        return res==m?-1:res;
    }
};