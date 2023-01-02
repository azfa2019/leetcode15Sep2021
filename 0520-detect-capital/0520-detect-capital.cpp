class Solution {
public:
    bool detectCapitalUse(string word) {
        int s=0;
        for(int i=0;i<word.size();i++) 
            if(isupper(word[i])) s++;
        return s==0||s==word.size()||s==1&&isupper(word[0]);
    }
};