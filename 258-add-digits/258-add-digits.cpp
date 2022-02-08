class Solution {
    public:
    int addDigits(int num) {
        if(num<10) return num;
        int ans=0;
        while(num>=10){
            ans=0;
            while(num){
                ans+=num%10;
                num/=10;
            }
            num=ans;
        }
        return ans;
    }
};