class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<char,pair<int,int>>hash{{'N',{-1,0}},{'S',{1,0}},{'E',{0,1}},{'W',{0,-1}}};
        unordered_set<string>st;
        st.insert("0_0");
        pair<int,int>cur{0,0};
        for(int i=0;i<path.size();i++){
            cur.first+=hash[path[i]].first;
            cur.second+=hash[path[i]].second;
            string pt=to_string(cur.first)+"_"+to_string(cur.second);
            if(st.count(pt)) return true;
            st.insert(pt);
            
        }
        return false;
    }
};