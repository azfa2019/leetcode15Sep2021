const int N=100010;
class Solution {
public:
    int f[N];
    bool seen[N],comp[N];
    int find(int x){
        return x==f[x]?x:find(f[x]);
    }
    void merge(int x,int y){
        int fx=find(x),fy=find(y);
        if(f[fx]!=fy) f[fx]=fy;
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        memset(seen,false,sizeof seen);
        int m=0;
        for(int i=0;i<n;i++){
            m=max(m,nums[i]);;
            seen[nums[i]]=true;
        }
        if(seen[1]) return false;
        for(int i=2;i<=m;i++) f[i]=i;
        memset(comp,false,sizeof comp);
        for(int x=2;x<=m;x++){
            if(comp[x]) continue;
            for(int y=x+x;y<=m;y+=x){
                comp[y]=true;
                if(seen[y]) merge(x,y);
            }
        }
        for(int i=1;i<n;i++)
            if(find(nums[i])!=find(nums[0])) return false;
        return true;
    }
};