/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
    int maxDepth=1;
    int sum=0;
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int depth=1;
        for(auto e:nestedList)
            dfs(e,depth);
        //cout<<maxDepth<<endl;
        depth=1;
        for(auto e:nestedList)
            dfsSum(e,depth);
        return sum;
    }
    void dfsSum(NestedInteger& nestedItem,int& depth){
        if(nestedItem.isInteger()==true) {
            int weight=(maxDepth-depth+1);
            int num=nestedItem.getInteger();
            sum+=weight*num;
            //cout<<weight<<" "<<num;
            return;
        }
        for(auto e:nestedItem.getList()){
            depth++;
            maxDepth=max(maxDepth,depth);
            dfsSum(e,depth);
            depth--;
        }
    }
    void dfs(NestedInteger& nestedItem,int& depth){
        if(nestedItem.isInteger()==true) return;
        for(auto e:nestedItem.getList()){
            depth++;
            maxDepth=max(maxDepth,depth);
            dfs(e,depth);
            depth--;
        }
    }
};
