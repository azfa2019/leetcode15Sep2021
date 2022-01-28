class WordDictionary {
    class Trie{
        public:
        Trie* child[26]={};
        bool isword=false;
        Trie(){};
    };
    Trie* root;
public:
    WordDictionary() {
        this->root=new Trie();
    }
    
    void addWord(string word) {
        auto node=root;
        for(char c:word){
            if(!node->child[c-'a']) node->child[c-'a']=new Trie();
            node=node->child[c-'a'];
        }
        node->isword=true;
    }
    
    bool search(string word) {
        auto node=root;
        return dfs(0,node,word);
    }
    bool dfs(int idx,Trie* node, string& word){
        if(!node) return false;
        if(idx==word.size()) return node->isword;
        if(word[idx]!='.'){
            //if(!node->child[word[idx]-'a']) return false;
            node=node->child[word[idx]-'a'];
            return dfs(idx+1,node,word);
        }else {
            for(auto next:node->child){
                if(dfs(idx+1,next,word)) return true;
            }
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