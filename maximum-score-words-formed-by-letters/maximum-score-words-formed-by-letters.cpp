class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
      vector<int>lettercnt(26,0);
      for(char c:letters) lettercnt[c-'a']++;
      int ans=0;
      int m=(1<<words.size());
      for(int state=0;state<m;state++){
        auto freq=countFreq(words,state);
        ans=max(ans,calScore(freq,lettercnt,score));
      }
      return ans;
    }
  vector<int> countFreq(vector<string>&words,int state){
    vector<int>freq(26,0);
    for(int i=0;i<words.size();i++){//check if words[i] exists in state, if yes, count which letters are used and for how many times
      if((state&(1<<i))==0) continue;
      for(char c:words[i]) freq[c-'a']++;
    }
    return freq;
  }
  int calScore(vector<int>&freq,vector<int>&lettercnt,vector<int>&score){
    int sum=0;
    for(int i=0;i<26;i++){
      if(lettercnt[i]<freq[i]) return 0;
      sum+=score[i]*freq[i];
    }
    return sum;
  }
};