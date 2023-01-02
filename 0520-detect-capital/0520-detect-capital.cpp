class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size()==1) return true;
        char c=word[0];
        if(c>='a'&&c<='z'){ //lower case
            for(int i=1;i<word.size();i++){
                char cur=word[i];
                if(cur<'a'||cur>'z') return false;
            }
        }else{ //upper case
            char one=word[1];
            if(one>='a'&&one<='z'){//lower case
                for(int i=2;i<word.size();i++)
                    if(word[i]<'a'||word[i]>'z') return false;
            }else//upper case
                for(int i=2;i<word.size();i++)
                    if(word[i]>='a'&&word[i]<='z') return false;
        }
        return true;
    }
};