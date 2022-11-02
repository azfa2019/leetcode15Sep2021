class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> hash(bank.begin(),bank.end());
        queue<string>q;
        q.push(start);
        unordered_set<string>visited;
        visited.insert(start);
        int step=0;
        while(q.size()){
            int len=q.size();
            for(int i=0;i<len;i++){
                auto cur=q.front();q.pop();
                if(cur==end) return step;
                for(char c:"ACGT"){
                    for(int j=0;j<cur.size();j++){
                        string next=cur;
                        next[j]=c;
                        if(hash.count(next) && !visited.count(next)) q.push(next),visited.insert(next);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};