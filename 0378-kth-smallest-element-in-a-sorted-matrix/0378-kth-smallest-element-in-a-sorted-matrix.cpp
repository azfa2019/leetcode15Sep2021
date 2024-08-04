class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size(),l=INT_MIN,r=INT_MAX;
        
        while(l<r){
            int mid=(long long) l+r>>1;
            int i=n-1,cnt=0;
            for(int j=0;j<n;j++){
                while(i>=0 && matrix[j][i]>mid) i--;
                cnt+=i+1;
            }
            if(cnt>=k) r=mid;
            else l=mid+1;
        }
        return l;
    }
};