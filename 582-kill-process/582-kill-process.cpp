class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int,vector<int>>hash;
        for(int i=0;i<pid.size();i++){
            int parent=ppid[i],son=pid[i];
            hash[parent].push_back(son);
        }
        vector<int>res;
        queue<int>q;
        q.push(kill);
        while(q.size()){
            auto t=q.front();q.pop();
            res.push_back(t);
            for(auto ne:hash[t]) q.push(ne);
        } 
        return res;
    }
};