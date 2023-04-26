class Solution {
public:
    int addDigits(int num) {
        while(num>=10){
            int s=0,t=num;
            while(t){
                s+=t%10;
                t/=10;
            }
            num=s;
        }
        return num;
    }
};