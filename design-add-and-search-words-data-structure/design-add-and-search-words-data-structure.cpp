class WordDictionary {
    class Trie{
        public:
        Trie* children[26]={};
        bool isWord=false;
        Trie(){};
    };
    Trie* root=new Trie();
public:
    WordDictionary() {
        
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
        return find(0,node,word);
    }
    bool find(int idx,Trie* node,string& word){
        if(node==nullptr) return false;
        if(idx==word.size()) return node->isWord;
        if(word[idx]=='.'){
            for(auto next:node->children){
                if(find(idx+1,next,word)==true) return true;
            }
        }else{
            auto next=node->children[word[idx]-'a'];
            return find(idx+1,next,word);
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