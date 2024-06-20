class Solution {
public:
    bool check(int x, vector<int>& p, int m){
        int cnt=0, target=p[0]+x;
        for(int i=0;i<p.size()-1;i++)
            if(p[i]<target && p[i+1]>=target) cnt++,target=p[i+1]+x;
        return cnt>=m-1;
    }
    int maxDistance(vector<int>& p, int m) {
        sort(p.begin(),p.end());
        int mn=INT_MAX;
        int n=p.size();
        for(int i=1;i<n;i++) mn=min(mn,p[i]-p[i-1]);
        int l=mn,r=(p[n-1]-p[0])/(m-1);
        while(l<r) {
            int mid=(l+r+1)/2;
            if(check(mid,p,m)) l=mid;
            else r=mid-1;
        }
        return l;
    }
};