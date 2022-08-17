class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>s{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."    };
        unordered_set<string>dict;
        for(string w:words){
                string cur;
                for(char c:w) cur+=s[c-'a'];
            dict.insert(cur);
        }
        return dict.size();
    }
};