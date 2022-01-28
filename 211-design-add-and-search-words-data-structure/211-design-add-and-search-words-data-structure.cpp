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
        root=new Trie();
    }

    void addWord(string word) {
        auto node=root;
        for(auto c:word){
            if(!node->child[c-'a']) node->child[c-'a']=new Trie();
            node=node->child[c-'a'];
        }
        node->isword=true;
    }

    bool search(string word) {
        auto node=root;
        return dfs(node,word,0);
    }
    bool dfs(Trie* node,string& word,int idx){
        if(!node) return false;
        if(idx==word.size()) return node->isword;
        if(word[idx]=='.'){
            for(auto next:node->child) 
                if(dfs(next,word,idx+1)) return true;
        }else{
            if(!node->child[word[idx]-'a']) return false;
            node=node->child[word[idx]-'a'];
            return dfs(node,word,idx+1);
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