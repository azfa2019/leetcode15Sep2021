class Trie{
    public:
    unordered_map<char,Trie*> child;
    bool isend=false;
    void insert(string& w){
        Trie* cur=this;
        for(char c:w){
            if(cur->child.find(c)==cur->child.end()) cur->child[c]=new Trie();
            cur=cur->child[c];
        }
        cur->isend=true;
    }
    bool search(string& w){
        Trie* cur=this;
        for(char c:w){
            if(cur->child.find(c)==cur->child.end()) return false;
            cur=cur->child[c];
            if(!cur->isend) return false;
        }
        return true;
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie tree;
        for(auto &w:words) tree.insert(w);
        sort(words.begin(),words.end(),[](const string&a,const string& b){
            if(a.size()!=b.size()) return a.size()>b.size();
            return a<b;
        });
        for(auto &w:words)
            if(tree.search(w)) return w;
        return "";
    }
};