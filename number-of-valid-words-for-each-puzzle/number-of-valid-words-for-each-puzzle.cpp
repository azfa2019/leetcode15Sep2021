class Solution {
  public:
  vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
    vector<int>ans;
    unordered_map<int,int>freq;
    for(string word:words){
      int mask=0;
      for(char c:word) mask|=(1<<(c-'a'));
      freq[mask]++;
    }
    for(string p:puzzles){
      int total=0;
      int l=p.size()-1;
      for(int i=0;i<(1<<l);i++){
        int mask=1<<(p[0]-'a');
        for(int j=0;j<l;j++){
          if(i&(1<<j)) mask|=1<<(p[j+1]-'a');
        }
        if(freq.find(mask)!=freq.end()) total+=freq[mask];
      }
      ans.push_back(total);
    }
    return ans;
  }
};