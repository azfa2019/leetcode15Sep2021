class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int p1=-1,p2=-1;
        int ans=1e6;
        for(int i=0;i<words.size();i++){
            if(words[i]==word1) p1=i;
            if(words[i]==word2){
                if(word1==word2) p1=p2;
                p2=i;
            }
            if(p1!=-1 && p2!=-1) ans=min(ans,abs(p2-p1));
        }
        return ans;
    }
};