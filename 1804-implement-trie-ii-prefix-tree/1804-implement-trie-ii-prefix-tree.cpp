class Trie {
    struct TrieNode{
        TrieNode* nodes[26];
        int cnt;
        int pcnt;
        TrieNode(){
            memset(nodes,0,sizeof nodes);
            cnt=0;
            pcnt=0;
        }
    };
    TrieNode* root;
public:
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* tmp=root;
        for(char c:word){
            int idx=c-'a';
            if(tmp->nodes[idx]==nullptr) tmp->nodes[idx]=new TrieNode();
            tmp=tmp->nodes[idx];
            tmp->pcnt++;
        }
        tmp->cnt++;
    }
    
    int countWordsEqualTo(string word) {
        TrieNode* tmp=root;
        for(char c:word){
            int idx=c-'a';
            if(tmp->nodes[idx]==nullptr) return 0;
            tmp=tmp->nodes[idx];
        }
        return tmp->cnt;
    }
    
    int countWordsStartingWith(string prefix) {
        TrieNode* tmp=root;
        for(char c:prefix){
            int idx=c-'a';
            if(tmp->nodes[idx]==nullptr) return 0;
            tmp=tmp->nodes[idx];
        }
        return tmp->pcnt;
    }
    
    void erase(string word) {
        TrieNode* tmp=root;
        TrieNode* del=nullptr;
        for(char c:word){
            int idx=c-'a';
            TrieNode* p=tmp;
            tmp=tmp->nodes[idx];
            tmp->pcnt--;
            if(del) delete del;
            if(tmp->pcnt==0){
                if(del==nullptr) p->nodes[idx]=nullptr;
                del=tmp;
            }
        }
        tmp->cnt--;
        if(del) delete del;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */