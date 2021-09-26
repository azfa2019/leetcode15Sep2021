class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
      uint32_t ans=0;
      //ans=ans|(1<<(31-0));
      //cout<<ans<<endl;
      //for(int i=0;i<32;i++)
      //if(n&(1<<i)!=0) cout<<"hi"<<endl;
      for(int i=0;i<32;i++){
        //cout<<"i="<<i<<endl;
        //cout<<(n&(1<<i)!=0)<<n<<endl;
        if((n&(1<<i))!=0) ans=ans|(1<<(31-i));
        //cout<<"ans="<<ans<<endl;
        //else ans|=(0<<(31-i));
      }
      return ans;
    }
};