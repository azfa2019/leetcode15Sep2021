class Solution {
public:
    int findTheWinner(int n, int k) {
        int vis[n];
        memset(vis,0,sizeof vis);
        int idx=0;
        for(int i=1;i<=n-1;i++){
            for(int j=1;j<=k;j++){
                if(vis[idx]==0) idx=(idx+1)%n;
                else{
                    while(vis[idx]) idx=(idx+1)%n;
                    idx=(idx+1)%n;
                }
            }
            vis[(idx-1+n)%n]=1;
        }
        for(int i=0;i<n;i++) 
            if(!vis[i]) return i+1;
        return -1;
    }
};