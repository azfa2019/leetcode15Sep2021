class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int>res(s.size()+1);
        for(int i=0;i<res.size();i++) res[i]=i+1;
        int pos=0;
        while(pos<s.size()){
            if(s[pos]=='I'){
                pos++;
                continue;
            }
            int start=pos;
            while(pos<s.size()&&s[pos]=='D') pos++;
            reverse(res.begin()+start,res.begin()+pos+1);
        }
        return res;
    }
};