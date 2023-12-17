class FoodRatings {
public:
    typedef pair<int,string>pis;
    map<string,pis>mp1;
    map<string,set<pis>>mp2;
    FoodRatings(vector<string>& f, vector<string>& c, vector<int>& r) {
        int n=c.size();
        for(int i=0;i<n;i++){
            string type=c[i];
            string food=f[i];
            mp1[food]={r[i],type};
            mp2[type].insert({-r[i],food});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto &p=mp1[food];
        mp2[p.second].erase({-p.first,food});
        p.first=newRating;
        mp2[p.second].insert({-p.first,food});
    }
    
    string highestRated(string cuisine) {
        return mp2[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */