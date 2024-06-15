class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& b, vector<int>& w) {
        int n=w.size();
        const int inf=INT_MAX;
        vector<int>left(n,inf),right(n,inf);
        for(int i=1;i<n;i++){
            left[i]=min(left[i-1],w[i-1]);
        }
        for(int i=n-2;~i;i--){
            right[i]=min(right[i+1],w[i+1]);
        }
        for(int i=0;i<n;i++) w[i]=min(w[i],max(left[i],right[i]));
        sort(b.begin(),b.end());
        sort(w.begin(),w.end());
        int ans=0,i=0;
        for(int x:b){
            while(i<n&&w[i]<x) i++;
            if(i==n) break;
            ans++,i++;
        }
        return ans;
    }
};