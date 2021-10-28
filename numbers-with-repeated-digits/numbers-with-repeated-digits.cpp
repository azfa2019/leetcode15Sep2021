class Solution {
  int count;
  //int digits[10];
  public:
  int numDupDigitsAtMostN(int n) {
    int tmp=n;
    vector<int>nums;
    while(tmp>0){
      nums.push_back(tmp%10);
      tmp/=10;
    }
    reverse(nums.begin(),nums.end());
    count=0;
    int m=nums.size();//how many digits are in n
    // 3 4 5 6 7 m=5, 1 to 4 digits, take out 1 digit, k=0 to 3 digits
    //k=0, 
    // 1 digits: 9*1
    // 2 digits: 9*permu(9,1)
    for(int k=1;k<m;k++){ //k is the digit position, 0 indexed, at most k is at position m-1
      count+=9*permu(9,nums.size()-(k+1));//k+1: because if k==1 (k at digit 1), the first digit is already selected, k is 0 based
    }
    cout<<count<<endl;
    //for(int k=0;k<=m-2;k++){ //original n is m digits, calculate the permutation of 1 digit to m-1 digit, first digit is 1~9, the rest of digits are 0 to m-2
    //  count+=9*permu(9,k);
    //}
    vector<int>digits(10,0);
    DFS(nums,digits,0);
    //cout<<count<<endl;
    return n-count;
  }
  void DFS(vector<int>&num, vector<int>&digits, int k)
    {
        if (k==num.size())
        {
            count++;
            return;
        }
        
        for (int i=0; i<=9; i++)
        {
            if (k==0 && i==0) continue;
            
            if (i<num[k])
            {
                if (digits[i]==1) continue;
                count+= permu(10-(k+1),num.size()-(k+1));
            }
            else if (i==num[k])
            {
                if (digits[i]==1) continue;
                digits[i] = 1;
                DFS(num, digits, k+1);
                digits[i] = 0;                
            }
            
        }
    }
  //void dfs(int k,int& count,vector<int>&nums){
  //  if(k==nums.size()){
  //    count++;
  //    return;
  //  }
  //  for(int i=0;i<=9;i++){
  //    if(k=0&&i==0) continue;
  //    if(i<nums[k]){
  //      if(digits[i]==1) continue;
  //      count+=permu(10-(k+1),nums.size()-(k+1));
  //    }else if(i==nums[k]){
  //      if(digits[i]==1) continue;
  //      digits[i]=1;
  //      dfs(k+1,count,nums);
  //      digits[i]=0;
  //    }
  //  }
  //}
  int permu(int n,int r){
    int ans=1;
    for(int i=0;i<r;i++)
      ans*=(n-i);
    return ans;
  }
};
