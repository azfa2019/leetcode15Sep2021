class CombinationIterator {
  string cur,end;
  string characters;
  int flag;
  int combinationLength;
  public:
  CombinationIterator(string characters, int combinationLength) {
    this->characters=characters;
    this->combinationLength=combinationLength;
    cur=characters.substr(0,combinationLength);
    end=characters.substr(characters.size()-combinationLength);
    this->flag=1;
  }
  string next() {
    if(flag==1){
      flag=0;
      return cur;
    }
    int i=cur.size()-1;
    while(i>=0 && cur[i]==characters[i+characters.size()-combinationLength]) i--;
    int j=0;
    //while(j<characters.size() && characters[j]==cur[j]) j++;
    while( characters[j]!=cur[i]) j++;
    for(int k=i;k<cur.size();k++){
      cur[k]=characters[j+1+k-i];
    }
    return cur;
  }
  bool hasNext() {
    return cur!=end;
  }
};
/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// 01234
// acfhx
//.  j
// acf
// ach

// acx
//  i
// afh

// afx
// ahx
// cfh