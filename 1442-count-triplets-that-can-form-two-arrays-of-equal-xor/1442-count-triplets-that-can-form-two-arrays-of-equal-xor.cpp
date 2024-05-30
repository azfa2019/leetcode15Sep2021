class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size(),res=0;
        for(int i=0;i<n;i++){
            int t=arr[i];
            for(int k=i+1;k<n;k++){
                t^=arr[k];
                if(t==0) res+=k-i;
            }
        }
        return res;
    }
};