int f[2010][2010];
class Solution {
public:
    unordered_map<int,int>hash;
    vector<int>stones;
    bool canCross(vector<int>& _stones) {
        stones=_stones;
        int n=stones.size();
        for(int i=0;i<n;i++) hash[stones[i]]=i;
        memset(f,-1,sizeof f);
        f[0][1]=1;
        for(int i=0;i<n;i++){
            if(dp(n-1,i)) return true;
        }
        return false;
    }
    int dp(int i,int j){
        if(f[i][j]!=-1) return f[i][j];
        f[i][j]=0;
        for(int k=max(1,j-1);k<=j+1;k++){
            if(hash.count(stones[i]-k)){
                int p=hash[stones[i]-k];
                if(dp(p,k)) {
                    f[i][j]=1;
                    break;
                }
            }
        }
        return f[i][j];
    }
};