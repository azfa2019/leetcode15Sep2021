class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string ans="";
        for(string& w:words){
            if(w.size()%2==0){
                if(checkeven(w)) {
                    ans=w;
                    break;
                }
            }
            else{
                if(checkodd(w)){
                    ans=w;
                    break;
                }
            }
        }
        return ans;
    }
    bool checkodd(string& s){
        int n=s.size();
        int c=n/2;
        for(int i=c,j=c;i>=0 && j<n;i--,j++){
            if(s[i]!=s[j]) return false;
        }
        return true;
    }
    bool checkeven(string& s){
        int n=s.size();
        int c=n/2-1;
        for(int i=c,j=c+1;i>=0 && j<n;i--,j++){
            if(s[i]!=s[j]) return false;
        }
        return true;
    }
};