class Solution {
    struct TrieNode{
        int count;
        vector<TrieNode*> next;
        TrieNode():count(0){
            next.resize(26,nullptr);
        }
    };
    void insert(TrieNode* root,string& s){
        TrieNode* cur=root;
        for(char& c:s){
            if(!cur->next[c-'a']) cur->next[c-'a']=new TrieNode();
            cur=cur->next[c-'a'];
            cur->count++;
        }
    }
    int query(TrieNode* root,string& s){
        int n=s.size();
        TrieNode* cur=root;
        for(int i=0;i<n;i++){
            cur=cur->next[s[i]-'a'];
            if(cur->count==1) return i;
        }
        return n;
    }
    void releaseTrie(TrieNode* root){
        if(!root) return;
        for(auto& p:root->next) releaseTrie(p);
        delete(root);
    }
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        int n=dict.size();
        vector<string>res(n);
        unordered_map<string,vector<int>>m;
        for(int i=0;i<n;i++){
            string& s=dict[i];
            int len=s.size();
            if(len<=3) res[i]=s;
            else{
                string abbr=s[0]+to_string(len-2)+s[len-1];
                m[abbr].push_back(i);
                res[i]=abbr;
            }
        }
        for(auto& p:m){
            if(p.second.size()<=1) continue;
            TrieNode* root=new TrieNode();
            for(int i:p.second) insert(root,dict[i]);
            for(int i:p.second){
                int len=dict[i].size();
                int j=query(root,dict[i]);
                if(j>=len-3) res[i]=dict[i];
                else res[i]=dict[i].substr(0,j+1)+to_string(len-2-j)+dict[i][len-1];
            }
            releaseTrie(root);
        }
        return res;
    }
};