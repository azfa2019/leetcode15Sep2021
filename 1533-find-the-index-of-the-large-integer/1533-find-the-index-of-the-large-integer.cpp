/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int n=reader.length();
        int l=0,r=n-1;
        int midl,midr;
        while(l<r){
            if((r-l)&1) midl=(r+l)>>1,midr=(r+l+1)>>1;
            else midl=midr=(l+r)>>1;
            int flag=reader.compareSub(l,midl,midr,r);
            if(flag>0) r=midl;
            else l=midr;
        }
        return l;
    }
};