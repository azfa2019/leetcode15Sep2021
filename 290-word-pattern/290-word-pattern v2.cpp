class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>map;
        unordered_map<string,char>rmap;
        stringstream ss(s);
        string cur;
        for(char c:pattern){
            if(!(ss>>cur) ||
              (map.find(c)!=map.end() && map[c]!=cur) ||
              (rmap.find(cur)!=rmap.end() && rmap[cur]!=c) ) 
                return false;
            map[c]=cur;
            rmap[cur]=c;
        }
        
        return (ss>>cur)?false:true;
    }
};
