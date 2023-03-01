class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int n=words.size();
        vector<vector<char>>w(n,vector<char>(n,'#'));
        for(int i=0;i<n;i++)
            for(int j=0;j<words[i].size();j++){
                if(words[i].size()>n) return false;
                w[i][j]=words[i][j];
            }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(w[i][j]!=w[j][i]) return false;
        return true;
    }
};