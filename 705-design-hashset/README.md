<h2><a href="https://leetcode.com/problems/design-hashset/">705. Design HashSet</a></h2><h3>Easy</h3><hr><div><p>Design a HashSet without using any built-in hash table libraries.</p>

<p>Implement <code>MyHashSet</code> class:</p>

<ul>
	<li><code>void add(key)</code> Inserts the value <code>key</code> into the HashSet.</li>
	<li><code>bool contains(key)</code> Returns whether the value <code>key</code> exists in the HashSet or not.</li>
	<li><code>void remove(key)</code> Removes the value <code>key</code> in the HashSet. If <code>key</code> does not exist in the HashSet, do nothing.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
<strong>Output</strong>
[null, null, null, true, false, null, true, null, false]

<strong>Explanation</strong>
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // return True
myHashSet.contains(3); // return False, (not found)
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // return True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // return False, (already removed)</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= key &lt;= 10<sup>6</sup></code></li>
	<li>At most <code>10<sup>4</sup></code> calls will be made to <code>add</code>, <code>remove</code>, and <code>contains</code>.</li>
</ul>
</div>

解法: 
- 算法: 模拟哈希表, 此题用的是拉链法, 用到了vector, 并且包括删除操作
- 时间复杂度: <img src="https://render.githubusercontent.com/render/math?math=O(1)"> 一般哈希函数是为了把一个很大的值域映射到一个比较小的值域. 此题key值为<img src="https://render.githubusercontent.com/render/math?math=10^6">, 需要映射到<img src="https://render.githubusercontent.com/render/math?math=10^4">, 所以定义N为10003即可.
- 映射用取模实现,key%N
- 拉链借用了vector而不是手写单链表. 所以用到了push_back() 和 erase()
- find定义为bool类型也可以
```
const int N=10003;
class MyHashSet {
    vector<int>h[N];
public:
    MyHashSet() {
        
    }
    int find(vector<int>&h,int x){
        for(int i=0;i<h.size();i++)
            if(h[i]==x) return i;
        return -1;
    }
    void add(int key) {
        int t=key%N;
        int k=find(h[t],key);
        if(k==-1) h[t].push_back(key);
    }
    
    void remove(int key) {
        int t=key%N;
        int k=find(h[t],key);
        if(k!=-1) h[t].erase(h[t].begin()+k);
    }
    
    bool contains(int key) {
        int t=key%N;
        int k=find(h[t],key);
        return k!=-1;
    }
};
```
