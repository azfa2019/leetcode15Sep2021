class Solution {
public:
    int maxScore(vector<int>& nums) {
        int m=nums.size();
        vector<vector<int>>g(m,vector<int>(m));
        int f[1<<m];
        memset(f,0,sizeof f);
        for(int i=0;i<m;i++)
            for(int j=0;j<m;j++)
                g[i][j]=gcd(nums[i],nums[j]);
        for(int k=0;k<1<<m;k++){
            int cnt=get(k);
            if(cnt%2==0){
               for(int i=0;i<m;i++){
                   if(k>>i&1){
                       for(int j=i+1;j<m;j++){
                           if(k>>j&1){
                               f[k]=max(f[k],f[k-(1<<i)-(1<<j)]+cnt/2*g[i][j]);
                           }
                       }
                   }
                
                }
            }
        }
        return f[(1<<m)-1];
            
    }
    int get(int x){
        int cnt=0;
        while(x) x-=lowbit(x),cnt++;
        return cnt;
    }
    int lowbit(int x){
        return x&(-x);
    }
};