class Trie {
  Trie* children[26]={};
  bool isword=false;
public:
    Trie(){
        
    }
    
    void insert(string word) {
      Trie* node=this;
      for(char c:word){
        if(node->children[c-'a']==nullptr) node->children[c-'a']=new Trie();
        node=node->children[c-'a'];
      }
      node->isword=true;
    }
    
    bool search(string word) {
      Trie* node=this;
      for(char c:word){
        if(node->children[c-'a']==nullptr) return false;
        node=node->children[c-'a'];
      }
      return node->isword==true;
    }
    
    bool startsWith(string prefix) {
      Trie* node=this;
      for(char c:prefix){
        if(node->children[c-'a']==nullptr) return false;
        node=node->children[c-'a'];
      }
      return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */