class Solution {
    public:
    string addBinary(string a, string b) {

        int carry=0;
        string ans;
        for(int i=a.size()-1,j=b.size()-1;i>=0 || j>=0;i--,j--){
            int sum=carry;
            sum+=i>=0?a[i]-'0':0;
            sum+=j>=0?b[j]-'0':0;
            ans.push_back((sum%2)+'0');
            carry=sum/2;
        }
        if(carry==1) ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
