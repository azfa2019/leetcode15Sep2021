class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_set<string>vers;
        unordered_map<string,unordered_map<string,double>>d;
        for(int i=0;i<equations.size();i++){
            string a=equations[i][0],b=equations[i][1];
            auto c=values[i];
            d[a][b]=c;
            d[b][a]=1/c;
            vers.insert(a);
            vers.insert(b);
        }
        for(auto k:vers)
            for(auto i:vers)
                for(auto j:vers)
                    if(d[i][k] && d[j][k]) d[i][j]=d[i][k]*d[k][j];
        vector<double>res;
        for(auto q:queries){
            auto a=q[0],b=q[1];
            if(d[a][b]) res.push_back(d[a][b]);
            else res.push_back(-1.0);
        }
        return res;
    }
};