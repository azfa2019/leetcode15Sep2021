class Solution {
    public:
    int romanToInt(string s) {
        unordered_map<char,int>hash{{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
        int ans=0;
        for(int i=0;i<s.size();i++){
            ans+=hash[s[i]];
            if(i>0 && (s[i]=='V' || s[i]=='X')&& (s[i-1]=='I')) ans-=2*hash[s[i-1]];
            else if(i>0 && (s[i]=='L' || s[i]=='C')&& (s[i-1]=='X')) ans-=2*hash[s[i-1]];
            else if(i>0 && (s[i]=='D' || s[i]=='M')&& (s[i-1]=='C')) ans-=2*hash[s[i-1]];
        }
        return ans;
    }
};