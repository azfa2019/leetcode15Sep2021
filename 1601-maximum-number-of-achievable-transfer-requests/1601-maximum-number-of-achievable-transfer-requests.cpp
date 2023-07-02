class Solution {
public:
    vector<vector<int>>rs;
    int maximumRequests(int n, vector<vector<int>>& _rs) {
        rs=_rs;
        int m=rs.size(),ans=0;
        for(int i=0;i<1<<m;i++){
            int cnt=get(i);
            if(cnt<=ans) continue;
            if(check(i)) ans=cnt;
        }
        return ans;
    }
    bool check(int s){
        vector<int> cnt(20,0);
        int sum=0;
        for(int i=0;i<16;i++){
            if(s>>i&1) {
                int a=rs[i][0],b=rs[i][1];
                if(++cnt[a]==1) sum++;
                if(--cnt[b]==0) sum--;
            }
        }
        return sum==0;
    }
    int get(int n){
        int cnt=0;
        while(n) {
            cnt++;
            n-=lowbit(n);
        }
        return cnt;
    }
    int lowbit(int x){
        return x&-x;
    }
};