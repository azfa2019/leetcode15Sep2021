class WordDictionary {
  class Trie{
    public:
    Trie* children[26]={};
    bool isword=false;
    Trie(){};
  };
  Trie* root;
  public:
  WordDictionary() {
    root=new Trie();
  }

  void addWord(string word) {
    Trie* node=root;
    for(char c:word){
      if(node->children[c-'a']==nullptr) node->children[c-'a']=new Trie();
      node=node->children[c-'a'];
    }
    node->isword=true;
  }

  bool search(string word) {
    Trie* node=root;
    return find(node,0,word);
  }
  bool find(Trie* node, int idx,string& word){
    if(node==nullptr) return false;
    if(idx==word.size()) return (node->isword)==true;
    if(word[idx]=='.'){
      for(auto next:node->children) {
        if(find(next,idx+1,word)==true) return true;
      }
    }else{
      char c=word[idx];
      auto next=node->children[c-'a'];
      return find(next,idx+1,word);
    }
    return false;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */