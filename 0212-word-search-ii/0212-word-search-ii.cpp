class Solution {
public:
    struct Node{
        int id;
        Node* son[26];
        Node(){
            id=-1;
            for(int i=0;i<26;i++) son[i]=0;
        }
    }*root;
    vector<vector<char>>g;
    unordered_set<int>ids;
    vector<vector<bool>>st;
    int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
    void insert(string& word,int& id){
        auto p=root;
        for(auto& c:word){
            int u=c-'a';
            if(!p->son[u]) p->son[u]=new Node();
            p=p->son[u];
        }
        p->id=id;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        g=board;
        root=new Node();
        for(int i=0;i<words.size();i++) insert(words[i],i);
        int n=g.size(),m=g[0].size();
        st=vector<vector<bool>>(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int u=g[i][j]-'a';
                if(root->son[u]) dfs(i,j,root->son[u]);
            }
        }
        vector<string>res;
        for(auto& id:ids) res.push_back(words[id]);
        return res;
    }
    void dfs(int& x,int& y,Node* p){
        if(p->id!=-1) ids.insert(p->id);
        st[x][y]=true;
        //g[x][y]='.';
        for(int i=0;i<4;i++){
            int a=x+dx[i],b=y+dy[i];
            if(a>=0 && a<g.size() && b>=0 && b<g[0].size() && !st[a][b]){
                int u=g[a][b]-'a';
                if(p->son[u]) dfs(a,b,p->son[u]);
            }
        }
        st[x][y]=false;
        
    }
};