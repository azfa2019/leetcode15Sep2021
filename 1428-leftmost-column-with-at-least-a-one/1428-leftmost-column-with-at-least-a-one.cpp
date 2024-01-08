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
    int n,m;
    int leftMostColumnWithOne(BinaryMatrix &b) {
        n=b.dimensions()[0],m=b.dimensions()[1];
        int res=m;
        for(int i=0;i<n;i++)
            res=min(res,helper(i,b));
        return res==m?-1:res;
    }
    int helper(int row,BinaryMatrix &b){
        int l=0,r=m-1;
        while(l<r){
            int mid=l+r>>1;
            if(b.get(row,mid)) r=mid;
            else l=mid+1;
        }
        //cout<<l<<endl;
        return b.get(row,l)==1?l:m;
    }
};