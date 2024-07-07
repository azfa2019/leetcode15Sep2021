class Solution {
public:
    int numWaterBottles(int num, int e) {
        int a=num,b=0,ans=num;
        while(num>=e){
            a=num/e, b=num%e;
            num=a+b;
            ans+=a;
            
        }
        return ans;
    }
};
// 15b = 15w =  1b 7w  =1b = 1w