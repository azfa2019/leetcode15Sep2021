class Solution {
public:
    bool winnerOfGame(string c) {
        int a=0,b=0;
        for(int i=1;i<c.size()-1;i++){
            if(c[i]=='A'&&c[i-1]=='A'&&c[i+1]=='A') a++;
            if(c[i]=='B'&&c[i-1]=='B'&&c[i+1]=='B') b++;
            
        }
        return a>b;
    }
};