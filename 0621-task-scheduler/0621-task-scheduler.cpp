class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>hash;
        for(auto& c:tasks){
            hash[c]++;
        }
        int maxc=0,cnt=0;
        for(auto& [k,v]:hash){
            maxc=max(maxc,v);
        }
        for(auto& [k,v]:hash){
            if(v==maxc) cnt++;
        }
        return max((maxc-1)*(n+1)+cnt,(int)tasks.size());
    }
};