typedef unsigned long long ULL;
const int P=131;
class Solution {
public:
    vector<ULL>ha,hb,p;
    int n,m;
    ULL get(vector<ULL>&h,int l,int r){
        return h[r]-h[l-1]*p[r-l+1];
    }
    bool check(int mid){
        unordered_set<int>hash;
        for(int i=mid;i<=n;i++) hash.insert(get(ha,i-mid+1,i));
        for(int i=mid;i<=m;i++){
            if(hash.count(get(hb,i-mid+1,i))) return true;
        }
        return false;
    }
    int findLength(vector<int>& a, vector<int>& b) {
        n=a.size(),m=b.size();
        ha.resize(n+1),hb.resize(m+1),p.resize(n+1);
        for(int i=1;i<=n;i++) ha[i]=ha[i-1]*P+a[i-1];
        for(int i=1;i<=m;i++) hb[i]=hb[i-1]*P+b[i-1];
        p[0]=1;
        for(int i=1;i<=n;i++) p[i]=p[i-1]*P;
        int l=0,r=n;
        while(l<r){
            int mid=l+r+1>>1;
            if(check(mid)) l=mid;
            else r=mid-1;
        }
        return l;
    }
};