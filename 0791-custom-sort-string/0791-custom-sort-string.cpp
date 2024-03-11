class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>pos;
        for(int i=0;i<order.size();i++) pos[order[i]]=i;
        sort(s.begin(),s.end(),[&](char a,char b){ return pos[a]<pos[b];});
        return s;
    }
};