class Trie {
  Trie* children[26]={};
  bool isWord=false;
public:
    Trie() {
        
    }
    
    void insert(string word) {
      Trie* root=this;
      for(char c:word){
        if(root->children[c-'a']==nullptr) root->children[c-'a']=new Trie();
        root=root->children[c-'a'];
      }
      root->isWord=true;
    }
    
    bool search(string word) {
      Trie* root=this;
      for(char c:word){
        if(root->children[c-'a']==nullptr) return false;
        root=root->children[c-'a'];
      }
      return root->isWord==true;
    }
    
    bool startsWith(string prefix) {
      Trie* root=this;
      for(char c:prefix){
        if(root->children[c-'a']==nullptr) return false;
        root=root->children[c-'a'];
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