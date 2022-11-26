struct Job{
    int l,r,w;
    bool operator <(const Job& W)const{
        return r<W.r;
    }
};
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<Job>jobs;
        for(int i=0;i<n;i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        vector<int>f(n);
        f[0]=jobs[0].w;
        for(int i=1;i<n;i++){
            f[i]=max(f[i-1],jobs[i].w);
            if(jobs[0].r<=jobs[i].l){
                int l=0,r=i-1;
                while(l<r){
                    int mid=l+r+1>>1;
                    if(jobs[mid].r<=jobs[i].l) l=mid;
                    else r=mid-1;
                }
                f[i]=max(f[i],f[l]+jobs[i].w);
            }
        }
        return f[n-1];
    }
};