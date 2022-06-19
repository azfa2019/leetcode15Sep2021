struct Trie{
    unordered_map<char, Trie*>child;
    priority_queue<string>words;
};
class Solution {
public:
    void insert(Trie* root,string& word){
        Trie* cur=root;
        for(char& c:word){
            if(!cur->child.count(c)) cur->child[c]=new Trie();
            cur=cur->child[c];
            cur->words.push(word);
            if(cur->words.size()>3) cur->words.pop();
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* root=new Trie();
        for(string& w:products) insert(root,w);
        vector<vector<string>>ans;
        Trie* cur=root;
        bool flag=false;
        for(char& c:searchWord){
            if(flag||!cur->child.count(c)) ans.push_back({}),flag=true;
            else{
                cur=cur->child[c];
                vector<string>select;
                while(cur->words.size()){
                    select.push_back(cur->words.top());
                    cur->words.pop();
                }
                reverse(select.begin(),select.end());
                ans.push_back(select);
            }
        }
        return ans;
    }
};