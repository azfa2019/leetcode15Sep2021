class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int cnt[n];memset(cnt,0,sizeof cnt);
        priority_queue<int,vector<int>,greater<>>idle;
        for(int i=0;i<n;i++) idle.push(i);
        priority_queue<pair<long,int>,vector<pair<long,int>>,greater<>>using_;
      sort(meetings.begin(),meetings.end(),[](auto&a,auto&b){return a[0]<b[0];});  
        for(auto&m: meetings){
            long st=m[0],ed=m[1],id;
            while(using_.size() && using_.top().first<=st){
                idle.push(using_.top().second);
                using_.pop();
            }
            if(idle.empty()){
                auto[e,i]=using_.top();
                using_.pop();
                ed+=e-st;
                id=i;
            }else{
                id=idle.top();
                idle.pop();
            }
            cnt[id]++;
            using_.emplace(ed,id);
        }
        int ans=0;
        for(int i=0;i<n;i++) if(cnt[i]>cnt[ans]) ans=i;
        return ans;
    }
};