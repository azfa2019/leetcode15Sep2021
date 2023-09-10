class Solution {
public:
    struct compare{
        bool operator()(const pair<char,int>&a,const pair<char,int>&b){
            return a.second<b.second;
        }
    };
    string rearrangeString(string s, int k) {
        if(k<=1) return s;
        unordered_map<char,int>freq;
        for(char c:s) freq[c]++;
        priority_queue<pair<char,int>,vector<pair<char,int>>,compare>maxHeap;
        for(auto e:freq) maxHeap.push(e);
        string res="";
        queue<pair<char,int>>q;
        while(maxHeap.size()){
            auto cur=maxHeap.top();maxHeap.pop();
            res+=cur.first;
            cur.second--;
            q.push(cur);
            if(q.size()==k){
                auto e=q.front();q.pop();
                if(e.second) maxHeap.push(e);
            }
        }
        return res.size()==s.size()?res:"";
    }
};