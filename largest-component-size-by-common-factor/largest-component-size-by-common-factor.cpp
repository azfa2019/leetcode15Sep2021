class Solution {
  int L=1e5;
  int father[100005];
  int findFather(int x){
    if(x!=father[x]) father[x]=findFather(father[x]);
    return father[x];
  }
  void unionNodes(int x,int y){
    x=father[x];
    y=father[y];
    if(x<y) father[y]=x;
    else father[x]=y;
  }
  vector<int>Eratosthenes(int n)
  {
    auto q=vector<int>(n+1,0);
    for (int i=2; i<=sqrt(n); i++)
    {
      if (q[i]==0)
      {
        int j=i*2;
        while (j<n)
        {
          q[j]=1;
          j+=i;
        }
      }
    }
    vector<int>primes;
    for (int i=2; i<=n; i++)
    {
      if (q[i]==0)
        primes.push_back(i);                
    }
    return primes;
  }
  public:
  int largestComponentSize(vector<int>& nums) {
    for(int i=0;i<L;i++) father[i]=i;
    vector<int>primes=Eratosthenes(sqrt(L));
    
    for(int i=0;i<nums.size();i++){
      int x=nums[i];
      for(int p:primes){
        if(x%p==0) {
          if(findFather(nums[i])!=findFather(p)) unionNodes(nums[i],p);
          while(x%p==0) x/=p;
        }
      }
      if(x>1)       
        if(findFather(nums[i])!=findFather(x)) unionNodes(x,nums[i]);
    }
    unordered_map<int,int>count;
    for(int i=0;i<nums.size();i++)
      count[findFather(nums[i])]++;
    int ans=0;
    for(auto e:count) ans=max(ans,e.second);
    return ans;
  }
};