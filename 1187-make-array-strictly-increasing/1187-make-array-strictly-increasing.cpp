class Solution {
public:
    int makeArrayIncreasing(vector<int>& a, vector<int>& b) {
        sort(b.begin(),b.end());
        int n=a.size(),m=b.size(),INF=2e9;
        b.push_back(INF);
        vector<vector<int>>f(n,vector<int>(m+1,INF));
        f[0][0]=a[0];
        for(int i=1;i<=m;i++) f[0][i]=min(a[0],b[0]);
        for(int i=1;i<n;i++)
            for(int j=0;j<=m;j++){
                if(f[i-1][j]<a[i]) f[i][j]=a[i];
                if(j){
                    int l=0,r=m;
                    while(l<r){
                        int mid=l+r>>1;
                        if(b[mid]>f[i-1][j-1]) r=mid;
                        else l=mid+1;
                    }
                    f[i][j]=min(f[i][j],b[l]);
                }
            }
        for(int i=0;i<=m;i++)
            if(f[n-1][i]<INF) return i;
        return -1;
        
    }
};