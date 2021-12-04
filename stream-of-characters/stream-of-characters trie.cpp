class StreamChecker {
    class Trie{
        public:
        Trie* children[26]={};
        bool isend=false;
        Trie(){};
    };
    Trie* root;
    string str;
    public:
    StreamChecker(vector<string>& words) {
        this->root=new Trie();
        for(string word:words){
            Trie* node=root;
            for(int i=word.size()-1;i>=0;i--){
                char c=word[i];
                if(node->children[c-'a']==nullptr) node->children[c-'a']=new Trie();
                node=node->children[c-'a'];
            }
            node->isend=true;
        }
    }

    bool query(char letter) {
        str.push_back(letter);
        Trie* node=root;
        for(int i=str.size()-1;i>=0;i--){
            char c=str[i];
            if(node->children[c-'a']==nullptr) return false;
            else{
                node=node->children[c-'a'];
                if(node->isend==true) return true;
            }
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
