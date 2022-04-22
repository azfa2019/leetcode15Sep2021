<h2><a href="https://leetcode.com/problems/design-hashmap/">706. Design HashMap</a></h2><h3>Easy</h3><hr><div><p>Design a HashMap without using any built-in hash table libraries.</p>

<p>Implement the <code>MyHashMap</code> class:</p>

<ul>
	<li><code>MyHashMap()</code> initializes the object with an empty map.</li>
	<li><code>void put(int key, int value)</code> inserts a <code>(key, value)</code> pair into the HashMap. If the <code>key</code> already exists in the map, update the corresponding <code>value</code>.</li>
	<li><code>int get(int key)</code> returns the <code>value</code> to which the specified <code>key</code> is mapped, or <code>-1</code> if this map contains no mapping for the <code>key</code>.</li>
	<li><code>void remove(key)</code> removes the <code>key</code> and its corresponding <code>value</code> if the map contains the mapping for the <code>key</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
<strong>Output</strong>
[null, null, null, 1, -1, null, 1, null, -1]

<strong>Explanation</strong>
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // The map is now [[1,1]]
myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= key, value &lt;= 10<sup>6</sup></code></li>
	<li>At most <code>10<sup>4</sup></code> calls will be made to <code>put</code>, <code>get</code>, and <code>remove</code>.</li>
</ul>
</div>

解法: 
- 算法: 模拟哈希表
- 时间复杂度: <img src="https://render.githubusercontent.com/render/math?math=O(1)">
- 此题和上一道题很类似, 但是需要使用pair<int,int>
- 关键是find函数, 仍然需要把key做映射,具体表现为取模

```
const int N=20003;
typedef pair<int,int> PII;
class MyHashMap {
    vector<PII>h[N];
public:
    MyHashMap() {
        
    }
    int find(vector<PII>&h,int key){
        for(int i=0;i<h.size();i++)
            if(h[i].first==key) return i;
        return -1;
    }
    void put(int key, int value) {
        int t=key%N;
        int k=find(h[t],key);
        if(k==-1) h[t].push_back({key,value});
        else h[t][k].second=value;
    }
    
    int get(int key) {
        int t=key%N;
        int k=find(h[t],key);
        if(k==-1) return -1;
        else return h[t][k].second;
    }
    
    void remove(int key) {
        int t=key%N;
        int k=find(h[t],key);
        if(k!=-1) h[t].erase(h[t].begin()+k);
    }
};
```
