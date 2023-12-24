class Solution {
public:
    int minOperations(string s) {
        return min(count('0','1',s),count('1','0',s));
    }
    int count(char c1, char c2,string s){
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(i%2==0 && s[i]!=c1) cnt++;
            if(i%2==1 && s[i]!=c2) cnt++;
        }
        return cnt;
    }
};