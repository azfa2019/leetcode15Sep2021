class Solution {
public:
    int passThePillow(int n, int time) {
        int k=time/(n-1),t=time%(n-1);
        if(k<1) return time+1;
        return k%2?n-t:t+1;
    }
};

//1 2 3 4