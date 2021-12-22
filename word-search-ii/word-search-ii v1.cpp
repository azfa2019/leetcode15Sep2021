class Solution {
    class Trie{
        public:
        Trie* children[26]={};
        string word="";
        Trie(){};
    };
    int m,n;
    int dir[5]={1,0,-1,0,1};
    vector<string>ans;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root=new Trie();
        for(auto w:words){
            Trie* node=root;
            for(char c:w){
                if(node->children[c-'a']==nullptr) node->children[c-'a']=new Trie();
                node=node->children[c-'a'];
            }
            node->word=w;
        }
        this-> m=board.size(),this->n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dfs(i,j,root,board);
            }
        }
        return ans;
    }
    void dfs(int i,int j,Trie* node,vector<vector<char>>& board){
        if(i<0||j<0 || i>m-1 || j>n-1||board[i][j]=='#') return;
        char c=board[i][j];
        if(node->children[c-'a']==nullptr) return;
        node=node->children[c-'a'];
        if(node->word!="") {
            ans.push_back(node->word);
            node->word="";
        }
        board[i][j]='#';
        for(int d=0;d<4;d++){
            int r=i+dir[d];
            int c=j+dir[d+1];
            dfs(r,c,node,board);
        }
        board[i][j]=c;
    }
};
