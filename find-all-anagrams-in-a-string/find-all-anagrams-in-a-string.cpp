class Solution {
  public:
  vector<int> findAnagrams(string s, string t) {//140
    int n=s.size();
    unordered_map<char,int>freq;
    int left=0,count=0;
    for(char c:t) freq[c]++;
    vector<int>ans;
    for(int right=0;right<n;right++){
      char r=s[right];
      if(freq.find(r)!=freq.end()) {
        freq[r]--;
        if(freq[r]==0) count++;
      }
      //cout<<"count="<<count<<endl;
      while(count==freq.size()) {
        char l=s[left++];
        if(freq.find(l)!=freq.end()) {
          if(freq[l]==0) count--;
          freq[l]++;
        }
        //cout<<right<<endl;
        //cout<<left<<endl;
        if(right-(left-1)+1==t.size()) ans.push_back(left-1);
      }
    }
    return ans;
  }
};