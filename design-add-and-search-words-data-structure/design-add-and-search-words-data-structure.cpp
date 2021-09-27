class WordDictionary {
  class Trie{
    public:
    Trie* children[26]={};
    bool isWord=false;
    Trie(){
    }
  };
  Trie* root;
  public:
  WordDictionary():root(new Trie()) {

  }

  void addWord(string word) {
    Trie* node=root;
    for(char c:word){
      if(node->children[c-'a']==nullptr) node->children[c-'a']=new Trie();
      node=node->children[c-'a'];
    }
    node->isWord=true;
  }

  bool search(string word) {
    Trie* node=root;
    return find(node,word,0);
  }
  bool find(Trie* node,string& word,int idx){
    if(node==nullptr) return false;
    if(idx==word.size()) return node->isWord;
    if(word[idx]=='.'){
      for(auto next:node->children)
        if(find(next,word,idx+1)) return true;
    }else{
      Trie* next=node->children[word[idx]-'a'];
      return find(next,word,idx+1);
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