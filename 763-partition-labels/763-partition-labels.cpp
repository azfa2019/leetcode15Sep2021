class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>last;
        int n=s.size();
        for(int i=0;i<n;i++) last[s[i]]=i;
        int start=0,end=0;
        vector<int>res;
        for(int i=0;i<n;i++){
            while(last[s[i]]>end) end=last[s[i]];
            if(i==end) {
                res.push_back(end-start+1);
                start=end=i+1;
            }
        }
        return res;
    }
};