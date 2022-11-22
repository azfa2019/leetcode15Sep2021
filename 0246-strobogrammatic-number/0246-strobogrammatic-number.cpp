class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char,char>map{{'0','0'},{'1','1'},{'6','9'},{'9','6'},{'8','8'}};
      string res;
        for(int i=num.size()-1;i>=0;i--){
            if(map.count(num[i])) res.push_back(map[num[i]]);
            else return false;
        }
        return res==num;
    }
};