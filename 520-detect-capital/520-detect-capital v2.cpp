class Solution {
public:
    bool detectCapitalUse(string word) {
      int upper=0,lower=0;
        for(char c:word){
            if(isupper(c)) upper++;
            else lower++;
        }
        if(isupper(word[0])) return upper==1 || upper==word.size();
        else return lower==word.size() && upper==0;
    }
};
