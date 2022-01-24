class Solution {
    public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        if(checkLowerCase(word[0])){
            for(char c:word) 
                if(checkUpperCase(c)) return false;
        }else{
            if(word.size()>1 && checkUpperCase(word[1]))
                for(int i=1;i<n;i++){
                    if(checkLowerCase(word[i])) return false;
                }
            else if(word.size()>1 && checkLowerCase(word[1]))
                for(int i=1;i<n;i++){
                    if(checkUpperCase(word[i])) return false;
                }
        }
        return true;
    }
    int checkLowerCase(char c){
        return (c-'a'<=26 && c-'a'>=0);
    }

    int checkUpperCase(char c){
        return (c-'A'<=26 && c-'A'>=0);
    }
};
