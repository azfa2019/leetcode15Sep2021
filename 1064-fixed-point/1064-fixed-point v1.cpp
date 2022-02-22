class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int n=arr.size();
        int l=0,r=n-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(arr[mid]-mid>=0) r=mid;
            else l=mid+1;
        }
        return arr[l]==l?arr[l]:-1;
    }
};
//-10,-5,0,3,7
// 0.  1 2 3 4
