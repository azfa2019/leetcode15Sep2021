class Solution {
public:
    vector<int>p;
    int find(int x){
        if(x!=p[x]) p[x]=find(p[x]);
        return p[x];
    }
    bool equationsPossible(vector<string>& es) {
      for(int i=0;i<26;i++) p.push_back(i);
        for(auto e:es){
            int a=e[0]-'a',b=e[3]-'a';
            if(e[1]=='=') p[find(a)]=find(b);
        }
        for(auto e:es){
            int a=e[0]-'a',b=e[3]-'a';
            if(e[1]=='!')
                if(find(a)==find(b)) return false;
        }
        return true;
    }
};